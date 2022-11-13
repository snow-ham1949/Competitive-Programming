#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


// 該做幾次Miller_Rabin, a的選項
// n < 4,759,123,141 3 : 2, 7, 61
// n < 1,122,004,669,633 4 : 2, 13, 23, 1662803
// n < 3,474,749,660,383 6 : pirmes <= 13
// n < 2^64 7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022

using u128 = __uint128_t;
// a * b % n
ll mul(ll a, ll b, ll n){
  u128 ans = a * b;
  return ans % n;
}

// bool Miller_Rabin(ll a, ll n){
//   // a 是質數, a == n
//   if((a %= n) == 0) return true;
//   // 判斷偶數
//   if(n % 2 == 0) return n == 2;
//   // n - 1 = 2^s * d
//   ll d = (n-1) / ((n-1)&(1-n));
//   ll s = __lg((n-1)&(1-n));
//   ll x = 1;
//   // 快速冪計算 x = a^d
//   while(d){
//     if(d&1)
//       x = (x * a) % n;
//     d >>= 1;
//     a = (a * a) % n;
//   }
//   if(x == 1 || x == n-1) return true;
//   while(--s){
//     if ((x = (x * x) % n) == n - 1) return true;
//   }
//   return false;
// }

bool Miller_Rabin(ll a, ll n) {
  if ((a = a % n) == 0) return 1;
  if (n % 2 == 0) return n == 2;
  ll tmp = (n - 1) / ((n - 1) & (1 - n));
  ll t = __lg(((n - 1) & (1 - n)));
  ll x = 1;
  for (; tmp; tmp >>= 1, a = mul(a, a, n))
    if (tmp & 1) x = mul(x, a, n);
  if (x == 1 || x == n - 1) return 1;
  while (--t)
    if ((x = mul(x, x, n)) == n - 1) return 1;
  return 0;
}

int main(){
  int t;
  //cin >> t;
  ll n;
  vector<ll> a2 = {2, 13, 23, 1662803};
  while((cin >> n)){
    bool flag = true;
    for(auto i:a2){
      if(!flag)
        break;
      flag = Miller_Rabin(i, n);
    }
    if(flag)
      cout << "Y\n";
    else
      cout << "N\n";
  }
}
