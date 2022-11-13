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
int a[mxn], b[mxn];

void solve()
{
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    if (abs(a[i] - b[j]) <= k) {
      i++, j++;
      ans++;
    }
    else { // abs(a[i] - b[j]) > k
      if (a[i] - b[j] > k) {
        j++;
      }
      else {
        i++;
      }
    }
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

