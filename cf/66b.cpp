#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1000 + 5;
int a[mxn];

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int j, k;
    for (j = i + 1; j <= n; j++) {
      if (a[j] > a[j - 1]) break;
    }
    for (k = i - 1; k >= 0; k--) {
      if (a[k] > a[k + 1]) break;
    }
    ans = max(ans, j - k - 1);
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

