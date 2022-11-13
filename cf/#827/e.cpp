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

ll pre[mxn];
int a[mxn], premax[mxn];

void solve()
{
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
    premax[i] = max(premax[i - 1], a[i]);
  }
  int k;
  while (q--) {
    cin >> k; 
    int l = 0, r = n + 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (premax[mid] > k) r = mid;
      else l = mid + 1;
    }
    cout << pre[l - 1] << " ";
  }
  cout << "\n";
  memset(a, 0, sizeof(a));
  memset(pre, 0, sizeof(pre));
  memset(premax, 0, sizeof(premax));
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

