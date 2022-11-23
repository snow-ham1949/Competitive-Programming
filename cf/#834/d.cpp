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
  ll n, m; cin >> n >> m;
  ll _n = n, cnt2 = 0, cnt5 = 0;
  ll k = 1;
  while (n && n % 2 == 0) {
    n /= 2;
    cnt2++;
  }
  while (n && n % 5 == 0) {
    n /= 5;
    cnt5++;
  }
  while (cnt2 < cnt5 && k * 2 <= m) {
    k *= 2;
    cnt2++;
  }
  while (cnt5 < cnt2 && k * 5 <= m) {
    k *= 5;
    cnt5++;
  }
  while (k * 10 <= m) {
    k *= 10;
  }
  if (k == 1) cout << _n * m << endl;
  else {
    k *= (m / k);
    cout << _n * k << endl;
  }
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

