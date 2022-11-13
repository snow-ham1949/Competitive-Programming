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
  ll n, m;
  while (scanf("%lld%lld", &n, &m) == 2 && n != 0 && m != 0) {
    ll carry = 0, cnt = 0;
    while (n != 0 || m != 0) {
      if ((n % 10 + m % 10 + carry) >= 10) {
        carry = 1;
        cnt++;
      } else {
        carry = 0;
      }
      n /= 10;
      m /= 10;
    }
    if (cnt == 0) {
      printf("No carry operation.\n");
    }
    else if (cnt == 1) {
      printf("%lld carry operation.\n", cnt);
    }
    else {
      printf("%lld carry operations.\n", cnt);
    }
  }
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

