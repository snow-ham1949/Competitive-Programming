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

int paths[mxn][mxn];
pii frm[mxn][mxn];
int n, m;
queue<pii> q;
pii A;
bool possible = false;
string ans;

bool monster = true; // true: monster bfs, false: A bfs

void retrace(pii p)
{   
    pii from = frm[p.fi][p.se];
    if (from == pii(0, 0)) return;
    if (from.fi == p.fi + 1) ans.pb('U');
    if (from.fi == p.fi - 1) ans.pb('D');
    if (from.se == p.se + 1) ans.pb('L');
    if (from.se == p.se - 1) ans.pb('R');
    retrace(from);
}

void chk(pii src, pii des)
{   
    int num = paths[src.fi][src.se];
    if (num + 1 < paths[des.fi][des.se]) {  
        paths[des.fi][des.se] = num + 1;
        q.push(des);
        frm[des.fi][des.se] = src;
    }
}

void bfs()
{   
    while (!q.empty())
    {   
        pii p = q.front(), nxt; q.pop();
        nxt = p; nxt.fi--; chk(p, nxt);
        nxt = p; nxt.fi++; chk(p, nxt);
        nxt = p; nxt.se--; chk(p, nxt);
        nxt = p; nxt.se++; chk(p, nxt);
        if (!monster && (p.fi == 1 || p.se == 1 || p.fi == n || p.se == m)) {   
            possible = true;
            cout << "YES" << endl;
            cout << paths[p.fi][p.se] << endl;
            retrace(p);
            return;
        }
    }
}

void solve()
{
    char ch;
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {   
        for (int j = 1; j <= m; j++)
        {   
            paths[i][j] = INT_MAX;
            cin >> ch;
            if (ch == 'M') {    
                q.push({i, j});
                paths[i][j] = 0;
            }
            if (ch == '#') paths[i][j] = 0;
            if (ch == 'A') {  
                A.fi = i, A.se = j;
            }
        }
    }
    bfs();
    monster = false;
    frm[A.fi][A.se] = pii(0, 0);
    paths[A.fi][A.se] = 0;
    q.push(A);
    bfs();
    if (possible) { 
        reverse(all(ans));
        cout << ans << endl;
    } else {    
        cout << "NO" << endl;
    }
    
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

