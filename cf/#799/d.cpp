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

int dh, dm;

void parse_time(string s, int &h, int &m)
{   
    h = stoi(s.substr(0, 2));
    m = stoi(s.substr(3, 2));
    return;
}

int is_palindrome(int h, int m)
{   
    string s = to_string(h);
    string t = to_string(m);
    if (s.length() == 1)
    {   
        s = "0" + s;
    }
    if (t.length() == 1)
    {   
        t = "0" + t;
    }
    if (s[0] == t[1] and s[1] == t[0]) return 1;
    else return 0;
}

void add_time(int &h, int &m)
{   
    m += dm;
    if (m >= 60) {  
        h++;
        m %= 60;
    }
    h += dh;
    h %= 24;
}

void solve()
{
    string s; int x;
    cin >> s >> x;
    int h, m;
    parse_time(s, h, m);
    int sh = h, sm = m; // start time
    dh = x / 60, dm = x % 60; // every x minutes
    int ans = 0;
    do {    
        ans += is_palindrome(h, m);
        add_time(h, m);
    } while (h != sh or m != sm);
    cout << ans << endl;

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


