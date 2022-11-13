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

vector<vector<vector<char>>> _map(4, vector<vector<char>>(4, vector<char>(4, '.')));

void init()
{   
    for (int i = 0; i < 4; i++)
    {   
        _map[i][1][1] = _map[i][1][2] = _map[i][2][1] = _map[i][2][2] = '*';
    }
    _map[0][1][1] = '.';
    _map[1][1][2] = '.';
    _map[2][2][1] = '.';
    _map[3][2][2] = '.';
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 2, vector<char>(m + 2, '.'));
    for (int i = 1; i <= n; i++)
    {   
        for (int j = 1; j <= m; j++)
        {   
            cin >> g[i][j];
        }
    }

    for (int i = 0; i <= n - 2; i++)
    {   
        for (int j = 0; j <= m - 2; j++)
        {   
            for (int id = 0; id < 4; id++)
            {   
                bool ok = 1;
                int skipr = (id == 0 or id == 1) ? 0 : 3;
                int skipc = (id == 0 or id == 2) ? 0 : 3;
                for (int dx = 0; dx < 4; dx++)
                {   
                    for (int dy = 0; dy < 4; dy++)
                    {   
                        if (dx == skipr and dy == skipc) continue;
                        if (g[i + dx][j + dy] != _map[id][dx][dy]) {    
                            ok = 0;
                            break;
                        }
                    }
                    if (!ok) break;
                }

                if (ok)
                {   
                    for (int dx = 1; dx <= 2; dx++)
                    {   
                        for (int dy = 1; dy <= 2; dy++)
                        {   
                            if (_map[id][dx][dy] == '*') {  
                                g[i + dx][j + dy] = '.';
                            }
                        }
                    }
                }
            }
        }
    }

    bool ans = 1;
    for (int i = 1; i <= n; i++)
    {   
        for (int j = 1; j <= m; j++)
        {   
            if (g[i][j] == '*') {   
                ans = 0;
                break;
            }
        }
        if (!ans) break;
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    AC;
	int t = 1;
	cin >> t;
    init();
	while (t--)
	{
		solve();
	}
    return 0;
}


