#include <bits/stdc++.h>

using namespace std;

#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define sep " "

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int a = n * (n + 1) / (2 * (x + y));
    if (a * 2 * (x + y) == n * (n + 1))
    {
        cout << "POSSIBLE\n";
        vector<int> ans;
        int num = a * x;
        for (int i = n; i >= 1; i--)
        {
            if (i <= num)
            {
                ans.push_back(i);
                num -= i;
            }
        }
        cout << ans.size() << "\n";
        for (int v : ans)
        {
            cout << v << sep;
        }
        cout << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
    AC;
    int t, cnt = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << cnt << ": ";
        solve();
        cnt++;
    }

    return 0;
}