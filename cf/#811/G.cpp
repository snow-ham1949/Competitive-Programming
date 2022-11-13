#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;

const double dinf = numeric_limits<double>::max();
const double dninf = numeric_limits<double>::min();
const double eps = 1e-9;
const int mod = 1e9 + 7;

#define AC ios_base::sync_with_stdio(0), cin.tie(0);
#define rep(i, j, k) for (int i = j; i < k; i++)
#define rep1(i, j, k) for (int i = j; i <= k; i++)
#define repb(i, j, k) for (int i = j; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define fi first
#define se second
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()

template <typename T>
using Prior = std::priority_queue<T>;
template <typename T>
using prior = std::priority_queue<T, vector<T>, greater<T>>;
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p) {
  return o << p.fi << ' ' << p.se << endl;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (auto elem : vec) os << elem << " ";
  return os;
}

#define debug
#ifdef debug
void trace_() { cerr << "\n"; }
template <typename T1, typename... T2>
void trace_(T1 t1, T2... t2) {
  cerr << ' ' << t1;
  trace_(t2...);
}
#define trace(...) cerr << "[" << #__VA_ARGS__ << "] :", trace_(__VA_ARGS__);
#else
#define trace(...) 49
#endif

ll ifloor(ll a, ll b) {
  if (b < 0) a *= -1, b *= -1;
  if (a < 0)
    return (a - b + 1) / b;
  else
    return a / b;
}

ll iceil(ll a, ll b) {
  if (b < 0) a *= -1, b *= -1;
  if (a > 0)
    return (a + b - 1) / b;
  else
    return a / b;
}

#define tp3 tuple<int, int, int>

void dfs(int u, int len, ll aa, ll bb, vector<vector<tp3>>& g, vi& ans, vb& vis)
{
	trace(u, len, aa, bb);
	if (aa >= bb) ans[u] = len;
	for (auto [v, a, b] : g[u]) {
		if (vis[v]) continue;
		vis[v] = true;
		dfs(v, len + 1, aa + a, bb + b, g, ans, vis);
		vis[v] = false;
	}
}


void solve()
{
	int n; cin >> n;
	vector<vector<tp3>> g(n + 1, vector<tp3>());
	rep1(i, 2, n)
	{
		ll p, a, b; cin >> p >> a >> b;
		g[i].emplace_back(p, a, b);
		g[p].emplace_back(i, a, b);
	}
	vi ans(n + 1, INT_MAX);
	vb vis(n + 1, false);
	vis[1] = true;
	ans[1] = 0;
	dfs(1, 0, 0ll, 0ll, g, ans, vis);
	rep(u, 2, n)
	{
		trace(u, ans[u]);
		cout << (ans[u] == INT_MAX ? 0 : ans[u]) << " ";
	}
	cout << endl;
}

int main() {
  AC;
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
  return 0;
}