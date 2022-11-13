#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 1e5 + 5;

vector<pii> g[mxn];
vector<ll> dis(mxn, 1e18);

void dijkstra(int st)
{
  // does not work for graph existing negative weight
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.emplace(0ll, st);
  dis[st] = 0;

  while (!pq.empty())
  {
    auto [du, u] = pq.top(); pq.pop();
    if (dis[u] != du) continue;

    for (auto &[v, w] : g[u])
    {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pq.emplace(dis[v], v);
      }
    }
  }
}

void solve()
{
  int n, m, s;
  cin >> n >> m >> s; 
  for (int i = 0, u, v, w; i < m; i++)
  {
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
  }
  dijkstra(s);
  for (int i = 1; i <= n; i++) cout << dis[i] << " ";
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

