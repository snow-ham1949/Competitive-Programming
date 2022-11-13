#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 100 + 5;
char g[maxn][maxn];

void solve()
{   
    int r, c;
    cin >> r >> c;
    bool flag = 0;
    for (int i = 0; i < r; i++)
    {   
        for (int j = 0; j < c; j++)
        {   
            cin >> g[i][j];
            if (g[i][j] == '^') flag = 1;
        }
    }
    if (r == 1 or c == 1) { 
        if (flag) cout << "Impossible\n";
        else {
            cout << "Possible\n";
            for (int i = 0; i < r; i++)
            {   
                for (int j = 0; j < c; j++)
                {   
                    cout << g[i][j];
                }
                cout << endl;
            }
        }
        return;
    }
    cout << "Possible\n";
    for (int i = 0; i < r; i++)
    {   
        for (int j = 0; j < c; j++)
        {   
            cout << "^";
        }
        cout << endl;
    }
}

int main()
{   
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {   
        printf("Case #%d: ", i);
        solve();
    }
}

