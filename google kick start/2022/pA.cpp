#include <bits/stdc++.h>

using namespace std;

#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define sep " "

string solve()
{
    int n; cin >> n;
    string s; cin >> s;
    bool d = 0, ue = 0, le = 0, sp = 0;
    for (char c : s)
    {
        if (isdigit(c)) d = 1;
        else if (c - 'A' >= 0 and c - 'A' <= 26) ue = 1;
        else if (c - 'a' >= 0 and c - 'a' <= 26) le = 1;
        else if (c == '#' or c == '@' or c == '*' or c == '&') sp = 1;
    }
    if (!d)
    {
        s += '1';
    }
    if (!ue)
    {
        s += 'A';
    }
    if (!le)
    {
        s += 'a';
    }
    if (!sp)
    {
        s += '#';
    }
    if (s.length() < 7)
    {
        int sn = s.length();
        for (int i = 0; i < 7 - sn; i++)
        {
            s += 'a';
        }
    }
    return s;
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