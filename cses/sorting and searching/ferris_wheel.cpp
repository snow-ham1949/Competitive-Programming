#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
int a[mxn], tag[mxn];

void solve()
{
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int l = 0, r = n - 1, ans = 0;
  while (l < r) {
    if (a[l] + a[r] > x) {
      r--;
    }
    else {
      ans++;
      tag[l] = tag[r] = 1;
      l++, r--;
    }
  }
  for (int i = 0; i < n; i++) {
    ans += (tag[i] == 0);
  }
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

