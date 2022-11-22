#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

void solve()
{
  int n; cin >> n;
  vector<int> v(n + 2, 0);
  for (int i = 1; i <= n; i++) cin >> v[i];
  vector<int> cnt1(n + 2, 0), cnt0(n + 2, 0);
  ll mx = 0;
  for (int i = 1; i <= n; i++) {
    if (!v[i]) mx += cnt1[i - 1];
    cnt1[i] += (cnt1[i - 1] + v[i]);
  }
  for (int i = n; i >= 1; i--) {
    cnt0[i] += (cnt0[i + 1] + !v[i]);
  }
  ll tmp = mx;
  for (int i = 1; i <= n; i++) {
    ll cur = tmp;
    if (v[i]) {
      cur += cnt1[i - 1];
      cur -= cnt0[i + 1];
    }
    else {
      cur += cnt0[i + 1];
      cur -= cnt1[i - 1];
    }
    mx = max(mx, cur);
  }
  cout << mx << endl;
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

