#include <bits/stdc++.h>

using namespace std;

#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long 
#define sep " "

const int maxn = 1e5 + 10;

struct ant {
    int p, d, id;
};

bool cmp_abs(int a, int b)
{
    return abs(a) < abs(b);
}

bool cmp_ant(struct ant a, struct ant b)
{
    return a.p < b.p;
}

void solve()
{
    int n, l; cin >> n >> l;
    int time[maxn];
    struct ant v[maxn];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].p >> v[i].d;
        v[i].id = i;
        if (v[i].d == 0)
        {
            time[i] = v[i].p;
        }
        else
        {
            time[i] = -(l - v[i].p);
        }
    }
    sort(time + 1, time + n + 1, cmp_abs);
    sort(v + 1, v + n + 1, cmp_ant);
    int head = 1, tail = n;
    vector<pair<int, int> > ans;
    for (int i = 1 ; i <= n; i++)
    {
        if (time[i] > 0)
        {
            ans.push_back(make_pair(time[i], v[head].id));
            head++;
        }
        else
        {
            ans.push_back(make_pair(-time[i], v[tail].id));
            tail--;
        }
    }

    sort(ans.begin(), ans.end());
    for (auto p : ans)
    {
        cout << p.second << sep;
    }
    cout << "\n";
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