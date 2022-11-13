#include <bits/stdc++.h>

using namespace std;

#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define sep " "
#define DEBUG

typedef struct Point
{
    int x, y;
    bool operator==(const Point &a) const
    {
        return (x == a.x && y == a.y);
    }
} Point;

typedef struct L
{
    Point s, e;
    int len;
} L;

bool check(L a, L b)
{
    return (a.s == b.s and a.len == b.len * 2) or (a.s == b.e and a.len == b.len * 2) or (a.e == b.s and a.len == b.len * 2) or (a.e == b.e and a.len == b.len * 2) or
           (a.s == b.s and a.len * 2 == b.len) or (a.s == b.e and a.len * 2 == b.len) or (a.e == b.s and a.len * 2 == b.len) or (a.e == b.e and a.len * 2 == b.len);
}

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> g[i][j];
        }
    }

    vector<L> all;

    for (int i = 0; i < r; i++)
    {
        int len = 0, first = 1;
        Point a, b;
        L l;
        for (int j = 0; j < c; j++)
        {
            if (g[i][j])
            {
                if (first)
                {
                    a.x = i, a.y = j;
                    first = 0;
                }
                len++;
            }
            else
            {
                if (len > 1)
                {
                    b.x = i, b.y = j - 1;
                    l.s = a, l.e = b, l.len = len;
                    all.push_back(l);
                }
                len = 0;
                first = 1;
            }
        }
        if (len > 1)
        {
            b.x = i, b.y = c - 1;
            l.s = a, l.e = b, l.len = len;
            all.push_back(l);
        }
    }

    for (int i = 0; i < c; i++)
    {
        int len = 0, first = 1;
        Point a, b;
        L l;
        for (int j = 0; j < r; j++)
        {
            if (g[j][i])
            {
                if (first)
                {
                    a.x = j, a.y = i;
                    first = 0;
                }
                len++;
            }
            else
            {
                if (len > 1)
                {
                    b.x = j - 1, b.y = i;
                    l.s = a, l.e = b, l.len = len;
                    all.push_back(l);
                }
                len = 0;
                first = 1;
            }
        }
        if (len > 1)
        {
            b.x = r - 1, b.y = i;
            l.s = a, l.e = b, l.len = len;
            all.push_back(l);
        }
    }

#ifdef DEBUG
    for (auto l : all)
    {
        fprintf(stdout, "length: %d, start: %d, %d, end: %d, %d\n",
                l.len, l.s.x, l.s.y, l.e.x, l.e.y);
    }
    cout << '\n';
#endif

    int num = all.size(), ans = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (check(all[i], all[j]))
            {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    AC;
    int t, cnt = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << cnt << ": ";
        solve();
        cnt++;
    }

    return 0;
}