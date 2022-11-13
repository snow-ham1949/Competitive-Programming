#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)a.size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
vector<int> g[mxn], rg[mxn]; // clue, reverse of clue
int in[mxn], rin[mxn]; // indegree, reverse of indegree
int val[mxn]; // value of input
int ans[mxn];
int n, m;

struct Node {
  int l, r, id;
  bool operator <(const Node& b) const {
    return l < b.l;
  }
} a[mxn];

void tpsort1() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      a[v].l = max(a[v].l, a[u].l + 1);
      --in[v];
      if (in[v] == 0) q.push(v);
    }
  }
}

void tpsort2() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (rin[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : rg[u]) {
      a[v].r = min(a[v].r, a[u].r - 1);
      --rin[v];
      if (rin[v] == 0) q.push(v);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    rg[i].clear();
    in[i] = 0;
    rin[i] = 0;
    ans[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    if (val[i] != 0) a[i] = {val[i], val[i], i};
    else a[i] = {1, n, i};
  }
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    g[x].push_back(y); in[y]++;
    rg[y].push_back(x); rin[x]++;
  }
  tpsort1(), tpsort2();
  for (int i = 1; i <= n; i++) {
    if (a[i].l > a[i].r) {
      puts("-1");
      return;
    }
  }
  sort(a + 1, a + n + 1);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i = 1, j = 1; i <= n; i++) {
    for (; j <= n && a[j].l <= i; j++) {
      pq.push({a[j].r, a[j].id});
    }
    if (pq.empty()) {
      puts("-1");
      return;
    }
    if (pq.top().X < i) {
      puts("-1");
      return;
    }
    int u = pq.top().Y; pq.pop();
    ans[u] = i;
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  //ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

