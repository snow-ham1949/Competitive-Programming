#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int DIR_LEN = 4;
int dr[DIR_LEN] = {-1, 0, 1, 0};
int dc[DIR_LEN] = {0, 1, 0, -1};
const int PATH_LEN = 48;
int p[PATH_LEN]; // path
const int GRID_SZ = 9;
int vis[GRID_SZ][GRID_SZ];

int tryPath(int pathidx, int curR, int curC) {
  
  if (!vis[curR - 1][curC] && !vis[curR + 1][curC] && vis[curR][curC - 1] && vis[curR][curC + 1]) return 0;
  if (vis[curR - 1][curC] && vis[curR + 1][curC] && !vis[curR][curC - 1] && !vis[curR][curC + 1]) return 0;
  if (curR == 7 && curC == 1) {
    if (pathidx == PATH_LEN) {
      return 1;
    }
    return 0;
  }
  if (pathidx == PATH_LEN) return 0;

  int ret = 0;
  vis[curR][curC] = 1;

  if (p[pathidx] < 4) {
    int nxtR = curR + dr[p[pathidx]], nxtC = curC + dc[p[pathidx]];
    if (!vis[nxtR][nxtC]) ret += tryPath(pathidx + 1, nxtR, nxtC);
  }
  else {
    for (int i = 0; i < DIR_LEN; i++) {
      int nxtR = curR + dr[i], nxtC = curC + dc[i];
      if (vis[nxtR][nxtC]) continue;
      ret += tryPath(pathidx + 1, nxtR, nxtC);
    }
  }

  vis[curR][curC] = 0;
  return ret;
}

void solve()
{
  string s; cin >> s;
  for (int i = 0; i < PATH_LEN; i++) {
    if (s[i] == 'U') p[i] = 0;
    else if (s[i] == 'R') p[i] = 1;
    else if (s[i] == 'D') p[i] = 2;
    else if (s[i] == 'L') p[i] = 3;
    else p[i] = 4;
  }
  
  memset(vis, 0, sizeof(vis));

  for (int i = 0; i < GRID_SZ; i++) {
    vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = 1;
  }

  int ans = tryPath(0, 1, 1);
  cout << ans << endl;
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

