#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

#define int ll
void solve()
{
  int n, x, y;
  cin >> n >> x >> y;
  string a, b;
  cin >> a >> b;
  int cnt = 0; // count of 1
  for (int i = 0; i < n; i++) {
    a[i] ^= b[i];
    cnt += a[i];
  }
  if (cnt % 2) {
    cout << -1 << endl;
    return;
  }
  if (cnt == 2) {
    int l, r;
    for (l = 0; !a[l]; l++);
    for (r = n - 1; !a[r]; r--);
    if (l + 1 == r) cout << min(x, 2 * y) << endl;
    else cout << y << endl;
  } else {
    cout << cnt / 2 * y << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

