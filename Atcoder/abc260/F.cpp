#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define endl '\n'

int main() {

    int s, t, m; 
    cin >> s >> t >> m;
    vector<vector<int> > adj(s + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v - s);
    }

    vector<vector<int> > dp(t + 1, vector<int>(t + 1, -1));
    for (int i = 1; i <= s; i++) {
        for (auto &u : adj[i]) {
            for (auto &v : adj[i]) {
                if (u == v) continue;
                if (dp[u][v] != -1) {
                    cout << i << " " << u + s << " " << v + s << " " << dp[u][v]<< "\n";
                    exit(0);
                }
                dp[u][v] = i;
            }
        }
    }

    printf("-1\n");

    return 0;
}