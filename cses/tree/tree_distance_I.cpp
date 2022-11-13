#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

const int mxn = 2e5 + 5;

vector<int> g[mxn];
int ans[mxn], n;

int bfs(int src) {
  queue<int> q;
  vector<int> d(n + 1, -1);
  d[src] = 0;
  q.push(src);
  ans[src] = max(ans[src], d[src]);

  int u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        ans[v] = max(d[v], ans[v]);
        q.push(v);
      }
    }
  }
  return u;
}

void solve()
{
#define eb emplace_back
  cin >> n;
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }

  int st = bfs(1);
  int ed = bfs(st);
  bfs(ed);

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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

