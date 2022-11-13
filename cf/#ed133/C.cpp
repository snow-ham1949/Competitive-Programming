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
  cout << endl;
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

int d[5] = {-1, 0, 1, 0, -1};
int m;
pii none = {-1, -1};

bool chk(pii p)
{
	return p.fi >= 0 and p.fi < 2 and p.se >= 0 and p.se < m;
}

void solve()
{
	cin >> m;
	vvi g(2, vi(m));
	vector<vb> vis(2, vb(m, false));
	rep(i, 0, 2)
	{
		rep(j, 0, m) cin >> g[i][j];
	}
	int time = 0;
	pii src = {0, 0};
	vis[0][0] = true;
	queue<pii> q;
	q.push(src);
	while (!q.empty())
	{
		pii p = q.front();
		q.pop();
		int minTime = INT_MAX;
		pii bestChoice = none;
		for (int i = 0; i < 5; i++)
		{
			pii pp = {p.fi + d[i], p.se + d[i + 1]};
			if (chk(pp) and !vis[pp.fi][pp.se]) {
				if (g[pp.fi][pp.se] < minTime) {
					minTime = g[pp.fi][pp.se];
					bestChoice = pp;
				}
			}
		}
		if (bestChoice != none){
			if (minTime <= time) {
				time++;
			} else {
				time = minTime + 1;
			}
			q.push(bestChoice);
			vis[bestChoice.fi][bestChoice.se] = 1;
		}
		
	}
	cout << time << endl;
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