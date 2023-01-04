// ref: https://usaco.guide/gold/dp-trees?lang=cpp#solution---tree-matching
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;

int dp[mxn][2];
vector<int> g[mxn];

void dfs(int u, int p) {
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[u][1] += max(dp[v][0], dp[v][1]);
    }
  }
  for (int v : g[u]) {
    if (v != p) {
      dp[u][0] = max(dp[u][0], dp[v][1] + 1 + dp[u][1] - max(dp[v][0], dp[v][1]));
    }
  }
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
  dfs(1, 0);
  cout << max(dp[1][0], dp[1][1]) << endl;
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

