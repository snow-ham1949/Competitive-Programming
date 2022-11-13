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


void solve()
{
	int n;
	pii bed;
	cin >> n >> bed.fi >> bed.se;
	pii ans = {-1, -1};
	vii alarm(n);
	for (int i = 0; i < n; i++)
	{
		cin >> alarm[i].fi >> alarm[i].se;
	}
	sort(all(alarm));
	for (int i = 0; i < n; i++)
	{
		auto [h, m] = alarm[i];
		if (h < bed.fi) continue;
		else if (h == bed.fi and m < bed.se) continue;
		else {
			if (m - bed.se >= 0) {
				ans.se = m - bed.se;
			} else {
				ans.se = m + 60 - bed.se;
				h--;
			}
			ans.fi = h - bed.fi;
			break;
		}
	}
	if (ans.fi == -1) {
		if (alarm[0].se - bed.se >= 0) {
			ans.se = alarm[0].se - bed.se;
		} else {
			ans.se = alarm[0].se + 60 - bed.se;
			alarm[0].fi--;
		}
		ans.fi = alarm[0].fi + 24 - bed.fi;
		
	}
	cout << ans;
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