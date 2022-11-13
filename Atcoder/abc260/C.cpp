#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define endl '\n'

int main() {

    int n, x, y;
    cin >> n >> x >> y;
    vector<long long int> r(n + 1), b(n + 1);
    r[1] = 0, b[1] = 1;
    for (int i = 2; i <= n; i++) {
        b[i] = r[i - 1] + b[i - 1] * y;
        r[i] = r[i - 1] + b[i] * x;
    }

    cout << r[n] << endl;

    return 0;
}