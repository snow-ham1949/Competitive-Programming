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

void solve()
{
	string w;
	int p;
	cin >> w >> p;
	int len = w.length();
	map<char, vi> index;
	int ans = 0;
	rep(i, 0, len) {
		ans += (w[i] - 'a' + 1);
		index[w[i]].pb(i);
	}
	if (ans <= p) cout << w << endl;
	else {
		for (auto it = index.rbegin(); it != index.rend(); it++) {
			int cost = ((*it).fi - 'a' + 1) * (*it).se.size();
			if ((ans - p) > cost) {
				ans -= cost;
				for (auto i : (*it).se) w[i] = '.';
			} else {
				int num = iceil(ans - p, ((*it).fi - 'a' + 1));
				ans -= num * ((*it).fi - 'a' + 1);
				rep(i, 0, num) w[(*it).se[i]] = '.';
			}
			if (ans <= p) break;
		}
		if (ans <= p) {
			for (char c : w) {
				if (c != '.') cout << c;
			}
		}
		cout << endl;
	}
	
}

int main() {
  AC;
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
  return 0;
}