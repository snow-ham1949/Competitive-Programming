#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
// #define debug

const int mxn = 1e5 + 5;

vector<int> g[mxn], new_g[mxn];
int dfn[mxn], low[mxn], in_stk[mxn], root[mxn];
int num_SCC, cnt;
stack<int> stk;
vector<int> root_nodes;

#define eb emplace_back

void tarjan(int u, int fa)
{
  // fa: father, for debugging
#ifdef debug
  fprintf(stderr, "start tarjan\nu: %d, father: %d\n", u, fa);
#endif
  dfn[u] = low[u] = ++cnt;
  stk.push(u);
  in_stk[u] = 1;

  for (int v : g[u])
  {
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (in_stk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }

#ifdef debug
  fprintf(stderr, "end of tarjan\nu: %d, father: %d\n", u, fa);
#endif
  if (dfn[u] == low[u]) {
    root_nodes.eb(u);
    int x;
    do {
      x = stk.top();
      stk.pop();
      root[x] = u;
      in_stk[x] = 0;
    } while (x != u);
    num_SCC++;
  }
}

void solve()
{
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++)
  {
    cin >> u >> v;
    g[u].eb(v);
  }

  for (int i = 1; i <= n; i++) 
  {
    if (!dfn[i]) tarjan(i, i);
  }

#ifdef debug
  for (int u : root_nodes) cerr << u << endl;
#endif

  vector<int> in(n + 1, 0);
  for (int u = 1; u <= n; u++)
  {
    for (int v : g[u])
    {
      if (root[v] != root[u]) {
        new_g[root[u]].eb(root[v]);
        in[root[v]]++;
      }
    }
  }

  int ans = 0;
  for (int u : root_nodes)
  {
    if (!in[u]) ans++;
  }
  
  cout << ans << endl;

  // clear
  for (int i = 0; i < mxn; i++)
  {
    g[i].clear();
    new_g[i].clear();
  }
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(in_stk, 0, sizeof(in_stk));
  memset(root, 0, sizeof(root));
  while (stk.size()) stk.pop();
  num_SCC = cnt = 0;
  root_nodes.clear();
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

