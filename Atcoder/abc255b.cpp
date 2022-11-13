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
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define pob pop_back()
#define pof pop_front()

template <typename T>
using Prior = priority_queue<T>;
template <typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p) {
  return o << p.fi << ' ' << p.se << endl;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (auto elem : vec) os << elem << " ";
  os << endl;
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

const int maxn = 1000 + 5;
int a[maxn];
pii p[maxn];
int n, k;

ll dis(pii x, pii y)
{
	return (ll)(x.fi - y.fi) * (ll)(x.fi - y.fi) + (ll)(x.se - y.se) * (ll)(x.se - y.se);
}

bool chk(ll r)
{
	vb ok(n, false);
	rep(i, 0, k)
	{
		pii src = p[a[i] - 1];
		rep(j, 0, n)
		{
			if (dis(src, p[j]) <= r) {
				ok[j] = 1;
			}
		}
	}
	
	rep(i, 0, n) {
		if (!ok[i]) return false;
	}
	return true;
}

void solve()
{
	cin >> n >> k;
	rep(i, 0, k) cin >> a[i];
	rep(i, 0, n) cin >> p[i].fi >> p[i].se;
	ll l = 0, r = 8e10;
	while (l < r) {
		trace(l, r);
		ll mid = l + ((r - l) >> 1);
		if (chk(mid)) r = mid;
		else l = mid + 1;
	}
	cout << fixed << setprecision(15) << sqrt(l) << endl;
}

int main() {
  AC;
	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
  return 0;
}