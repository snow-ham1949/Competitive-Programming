#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define endl '\n'

bool cmp(const pii &a, const pii &b) {
    return (a.first > b.first) || (a.first == b.first and a.second < b.second);
}

int main() {

    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pii> math(n), english(n), both(n);
    for (int i = 0; i < n; i++) {
        cin >> math[i].first;
        both[i].first = math[i].first;
        math[i].second = both[i].second = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> english[i].first;
        both[i].first += english[i].first;
        english[i].second = i + 1;
    }

    sort(math.begin(), math.end(), cmp);
    sort(english.begin(), english.end(), cmp);
    sort(both.begin(), both.end(), cmp);

    // cerr << "math: ";
    // for (auto &it : math) cerr << it.second << " ";
    // cerr << "\nenglish: ";
    // for (auto &it : english) cerr << it.second << " ";
    // cerr << "\nboth: ";
    // for (auto &it : both) cerr << it.second << " ";
    // cerr << endl;

    set<int> s;
    for (int i = 0; i < x; i++) {
        s.insert(math[i].second);
    }

    int id = 0;
    while(y) {
        if (s.find(english[id].second) == s.end()) {
            s.insert(english[id].second);
            y--;
        }
        id++;
    }

    id = 0;
    while (z) {
        if (s.find(both[id].second) == s.end()) {
            s.insert(both[id].second);
            z--;
        }
        id++;
    }

    for (auto v : s) {
        cout << v << endl;
    }

    return 0;
}