#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


// 該做幾次Miller_Rabin, a的選項
// n < 4,759,123,141 3 : 2, 7, 61
// n < 1,122,004,669,633 4 : 2, 13, 23, 1662803
// n < 3,474,749,660,383 6 : pirmes <= 13
// n < 2^64 7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022

using u64 = uint64_t;
using u128 = __uint128_t;

// a * b % n
u64 mul(u64 a, u64 b, u64 n){
  u128 ans = (u128)a * (u128)b;
  return ans % n;
}

bool Miller_Rabin(u64 a, u64 n) {
  if ((a = a % n) == 0) return 1;
  if (n % 2 == 0) return n == 2;
  u64 tmp = (n - 1) / ((n - 1) & (1 - n));
  u64 t = __lg(((n - 1) & (1 - n)));
  u64 x = 1;
  for (; tmp; tmp >>= 1, a = mul(a, a, n))
    if (tmp & 1) x = mul(x, a, n);
  if (x == 1 || x == n - 1) return 1;
  while (--t)
    if ((x = mul(x, x, n)) == n - 1) return 1;
  return 0;
}

int main() {
  ll n;
  vector<u64> a = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  cin >> n;
  for (ll i = 0; i < n; i++){
    u64 x; cin >> x;
    bool flag = true;
    for(auto num : a){
      flag = Miller_Rabin(num, x);
      if (!flag) break;
    }
    if(flag)  cout << "Prime\n";
    else cout << "Not prime\n";
  }
}
