#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{   
    int n, k;
    cin >> n >> k;
    vector<int> v(100 + 5, 0);
    for (int i = 0; i < n; i++)
    {   
        int s; cin >> s;
        v[s]++;
    }
    if (n > k * 2) {    
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= 100; i++)
    {   
        if (v[i] > 2) { 
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

