#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 100;
char g[mxn + 5][mxn + 5];
int n, m;

bool chk(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void solve()
{
  for (int i = 0 ; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '*') continue;
      else {
        int cnt = 0;
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int x = i + dx, y = j + dy;
            if (chk(x, y) && g[x][y] == '*') {
              cnt++;
            }
          }
        }
        g[i][j] = '0' + cnt;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << g[i][j];
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (cin >> n >> m && (n != 0 || m != 0))
  {
    if (t > 1) cout << "\n";
    cout << "Field #" << t << ":" << "\n";
    solve(); 
    t++;
  }
  return 0;
}

