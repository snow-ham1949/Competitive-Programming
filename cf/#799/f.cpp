#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

const double dinf = numeric_limits<double>::max();
const double dninf = numeric_limits<double>::min();
const double eps = 1e-9;
const int mod = 1e9 + 7;

#define AC ios_base::sync_with_stdio(0), cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
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
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}
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

const int maxn = 2e5 + 5;
int a[maxn], digit[10];

void solve()
{
	int n; cin >> n;
    memset(a, 0, sizeof(a));
    memset(digit, 0, sizeof(digit));
    for (int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        digit[a[i] % 10]++;
    }
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {   
        int last = a[i] % 10;
        digit[last]--;
        int sum = (3 - last + 10) % 10;
        for (int x = 0; x < 10; x++)
        {   
            int y = (sum - x + 10) % 10;
            if (x == y and digit[x] >= 2) flag = 1;
            else if (x != y and digit[x] and digit[y]) flag = 1;
        }
        digit[last]++;
    }
    if (flag) puts("YES");
    else puts("NO");
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


