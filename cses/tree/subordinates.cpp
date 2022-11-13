#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;

int a[mxn];
vector<int> g[mxn];

void dfs(int u) {
  for (int v : g[u]) {
    dfs(v);
    a[u] += (a[v] + 1);
  }
}

void solve()
{
  int n; cin >> n;
  for (int i = 2, x; i <= n; i++) {
    cin >> x;
    g[x].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
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

