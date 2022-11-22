#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

#define ALL(v) (v).begin(), (v).end()

vector<ll> v;
ll n, c, d;

bool check(ll k) {
  ll sum = 0;
  for (int i = 0; i < d; i++) {
    if (i % (k + 1) < n) sum += v[i % (k + 1)];
  }
  if (sum >= c) return 1;
  return 0;
}

void solve()
{
  cin >> n >> c >> d;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  sort(ALL(a));
  if ((ll)a[n - 1] * d < c) {
    cout << "Impossible\n";
    return;
  }
  ll suf = 0, days = 0;
  for (int i = n - 1; i >= 0; i--) {
    suf += a[i];
    days++;
    if (days == d) break;
  }
  if (suf >= c) {
    cout << "Infinity\n";
    return;
  }
  v.resize(n);
  for (int i = 0; i < n; i++) {
    v[i] = a[n - 1 - i];
  }
  ll l = 0, r = d + 1;
  while (r - l > 1) {
    ll m = (l + r) >> 1;
    if (check(m)) l = m;
    else r = m;
  }
  cout << l << endl;
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

