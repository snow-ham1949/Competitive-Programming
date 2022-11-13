#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

ll sum[18 + 5];

ll fpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

void init() {
  for (ll digit = 1ll; digit <= 18ll; digit++) {
    sum[digit] = 9ll * fpow(10ll, digit - 1) * digit;
  }
}

void solve()
{
  ll k; cin >> k;
  int sz = -1;
  for (int digit = 1; digit <= 18; digit++) {
    if (k <= sum[digit]) {
      sz = digit;
      break;
    } else {
      k -= sum[digit];
    }
  }
  k--;
  ll x = k / sz;
  ll y = k % sz;
  ll num = fpow(10ll, sz - 1) + x;
  string s = to_string(num);
  cout << s[y] << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  init();
  while (t--)
  {
    solve(); 
  }
  return 0;
}

