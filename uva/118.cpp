#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 50 + 5;
int scent[mxn][mxn];
int n, m;

char oris[4] = {'N', 'E', 'S', 'W'};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool chk(int x, int y) {
  return x < 0 || x >= n + 1 || y < 0 || y >= m + 1;
}

void solve()
{
  cin >> n >> m;
  int x, y; 
  char ori;
  string inst;
  while (cin >> x >> y >> ori >> inst) {
    int lost = 0, dir = -1;
    for (int i = 0; i < 4; i++) {
      if (ori == oris[i]) {
        dir = i;
      }
    }
    for (int i = 0; inst[i]; i++) {
      if (inst[i] == 'R') {
        dir = (dir + 1) % 4;
      }
      else if (inst[i] == 'L') {
        dir = (dir - 1 + 4) % 4;
      }
      else {
        int tx = x + dx[dir], ty = y + dy[dir];
        if (chk(tx, ty)) {
          if (!scent[y][x]) {
            scent[y][x] = lost = 1;
            break;
          }
        } else {
          x = tx, y = ty;
        }
      }
    }
    cout << x << " " << y << " " << oris[dir] << (lost ? " LOST" : "") << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}
