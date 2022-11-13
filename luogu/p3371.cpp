#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 10000 + 5;

int n, m, s;
bitset<mxn> inque;
vector<pii> g[mxn];
queue<int> q;
ll dis[mxn], cnt[mxn];

bool SPFA(int st) {
  for (int i = 1; i <= n; i++) dis[i] = (1ll << 31) - 1;
  q.emplace(st);
  dis[st] = 0;
  
  while (!q.empty())
  {
    int u = q.front(); q.pop();
    inque[u] = 0;
    for (auto [v, w] : g[u])
    {
      if (dis[v] > dis[u] + w) {
        if (++cnt[v] >= n) return false; // contains negative cycle
        dis[v] = dis[u] + w;

        if (!inque[v]) {
          inque[v] = 1;
          q.emplace(v);
        }
      }
    }
  }

  return true;
}

void solve()
{
  cin >> n >> m >> s;
  #define eb emplace_back
  for (int i = 0, u, v, w; i < m; i++)
  {
    cin >> u >> v >> w;
    g[u].eb(v, w);
  }
  SPFA(s);
  for (int i = 1; i <= n; i++) cout << dis[i] << " ";
  cout << endl;
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

