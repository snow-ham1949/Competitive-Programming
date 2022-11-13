#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define endl '\n'

int main() {

    int n, k; cin >> n >> k;
    vector<int> pile(n + 1, 0), under(n + 1, -1), ans(n + 1, -1);
    set<int> s;
    for (int step = 1; step <= n; step++) {
        int card; cin >> card;
        auto it = s.upper_bound(card);
        if (it == s.end()) {
            pile[card] = 1;
            s.insert(card);
        } else {
            pile[card] = pile[*it] + 1;
            under[card] = *it;
            s.erase(it);
            s.insert(card);
        }

        if (pile[card] == k) {
            s.erase(card);
            int tmp = card;
            for (int i = 0; i < k; i++) {
                ans[tmp] = step;
                tmp = under[tmp];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}