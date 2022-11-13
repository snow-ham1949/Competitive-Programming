#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define eb emplace_back
const int mxn = 1e5 + 5;
vector<int> g[mxn];
int in[mxn]; // indegree
int n, m;

vector<int> tpsort()
{
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i++) 
  {
    if (in[i] == 0) pq.push(i);
  }
  
  vector<int> vec;
  while (!pq.empty())
  {
    int u = pq.top(); pq.pop();
    vec.emplace_back(u);
    for (auto v : g[u])
    {
      --in[v];
      if (in[v] == 0) pq.push(v);
    }
  }

  return vec;
}

void solve()
{
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++)
  {
    cin >> u >> v;
    g[u].eb(v);
    ++in[v];
  }
  vector<int> v = tpsort();
  for (auto i : v) cout << i << " ";
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

