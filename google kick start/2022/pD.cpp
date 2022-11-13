#include <bits/stdc++.h>

using namespace std;

#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long 
#define sep " "
#define mod 1000000007

bool isPanlidrome(string s)
{
    ll n = s.length();
    for (ll i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b, a%b, x, y);
    ll t = x;
    x = y;
    y = t - a/b* y;
    return r;
}

ll num = 0, sum = 0;

void cnt(string s, ll n)
{
    if (n == 0)
    {
        num++, sum++;
        return;
    }
    if (isPanlidrome(s)) num++;
    for (ll i = 0; i < n; i++)
    {
        string tmp = s;
        tmp.erase(i, 1);
        cnt(tmp, n - 1);
    }
}

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

ll get(ll a, ll b, ll m)
{
    ll x, y;
    ll d = extgcd(a, m, x, y);
    if (b % d == 0)
    {
        x %= m;
        while (x < 0)
        {
            x += m;
        }
        x %= m;
        return x * (b / d) % (m / d);
    }
    else
    {
        return m;
    }
}

void solve()
{
    ll n; cin >> n;
    string s; cin >> s;
    num = 0, sum = 0;
    cnt(s, n);
    // cout << "num: " << num << " sum: " << sum << "\n";
    ll gcd = __gcd(num, sum);
    ll tmp = num / sum;
    if (tmp * sum == num)
    {
        cout << tmp << "\n";
    }
    else
    {
        num /= gcd, sum /= gcd;
        cout << get(sum, num, mod) << "\n";
    }
}

int main()
{
    AC;
    ll t, cnt = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << cnt << ": ";
        solve();
        cnt++;
    }

    return 0;
}