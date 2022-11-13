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

const int mxn = 1000 + 5;
ll dp[mxn][mxn];
char g[mxn][mxn];

void solve()
{
	int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> g[i][j];
    for (int i = 0; i < n; i++)
    {   
        if (g[i][0] == '.') dp[i][0] = 1;
        else break;
    }
    for (int i = 0; i < n; i++)
    {   
        if (g[0][i] == '.') dp[0][i] = 1;
        else break;
    }
    for (int i = 1; i < n; i++)
    {   
        for (int j = 1; j < n; j++)
        {   
            if (g[i][j] == '.') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
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

