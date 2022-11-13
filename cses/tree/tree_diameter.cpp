#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;

vector<int> g[mxn];

pii bfs(int src) {
  queue<pii> q;
  q.push({src, 0});
  vector<bool> vis(mxn, false);
  
  pii p;
  while (!q.empty()) {
    p = q.front();
    q.pop();
    vis[p.first] = 1;
    for (int v : g[p.first]) {
      if (!vis[v]) {
        q.push({v, p.second + 1});
      }
    }
  }
  return p;
}

void solve()
{
#define eb emplace_back
  int n; cin >> n;
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }
  auto [st, tmp] = bfs(1);
  auto [ed, dis] = bfs(st);
  cout << dis << endl;
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
