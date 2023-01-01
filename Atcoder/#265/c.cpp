#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

void solve()
{
  int h, w; cin >> h >> w;
  vector<string> g(h);
  for (auto &s : g) cin >> s;
  vector<vector<bool>> vis(h, vector<bool>(w, false));

  int x = 0, y = 0;
  while (1) {
    if (vis[x][y]) {
      cout << "-1\n";
      return;
    }
    vis[x][y] = true;
    if (g[x][y] == 'U' && x != 0) x--;
    else if (g[x][y] == 'D' && x != h - 1) x++;
    else if (g[x][y] == 'L' && y != 0) y--;
    else if (g[x][y] == 'R' && y != w - 1) y++;
    else break;
  }
  cout << x + 1 << " " << y + 1 << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

