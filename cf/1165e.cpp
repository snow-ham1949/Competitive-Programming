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
const int mod = 998244353;

void solve()
{
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(b, b + n);
  vector<pair<ll, int>> val(n);
  for (int i = 0; i < n; i++) {
    val[i].X = (n - i) * 1ll * (i + 1) * a[i];
    val[i].Y = i;
  }
  sort(val.rbegin(), val.rend());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + (val[i].X * 1ll % mod) * b[i] % mod) % mod;
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

