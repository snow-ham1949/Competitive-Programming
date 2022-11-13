#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

const int mxn = 1e5 + 5;

int a[mxn];

void solve()
{
  int n; cin >> n; 
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 1, pre = a[0], len = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] >= pre) {
      len++;
    } else {
      ans = max(ans, len);
      len = 1;
    }
    pre = a[i];
  }
  ans = max(ans, len);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

