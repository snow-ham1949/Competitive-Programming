#include <bits/stdc++.h>

using namespace std;

#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define sep " "

int solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            cnt++;
        }
    }

    if (cnt == k)
    {
        return 0;
    }

    return abs(cnt - k);
}

int main()
{
    AC;
    int t, cnt = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << cnt << ": " << solve() << '\n';
        cnt++;
    }

    return 0;
}