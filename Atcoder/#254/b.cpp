#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int> > v(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i) v[i][j] = 1;
            else v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : v[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}
