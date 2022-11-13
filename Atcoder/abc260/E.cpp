#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define endl '\n'

int main() {

    int n, m; cin >> n >> m;
    vector<int> ans(m + 5, 0);
    vector<vector<int>> v(m + 1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(i);
        v[b].push_back(i);
    }

    vector<int> contains(n, 0);
    int cnt = n;
    for (int l = 1, r = 1; l <= m; l++) {
        while (r <= m and cnt != 0)
        {
            for (auto &id : v[r]) {
                ++contains[id];
                if (contains[id] == 1) cnt--;
            }
            r++;
        }

        if (cnt != 0) break;
        ans[r - l]++, ans[m + 1 - l + 1]--;

        for (auto &id: v[l]) {
            --contains[id];
            if (contains[id] == 0) cnt++;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        ans[i] += ans[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}