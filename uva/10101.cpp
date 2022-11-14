#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

void solve(ll n)
{
  if (n >= 10000000) {
    solve(n / 10000000);
    printf(" kuti");
    n %= 10000000;
    if (n > 0) printf(" ");
  }
  if (n >= 100000) {
    printf("%lld lakh", n / 100000);
    n %= 100000;
    if (n > 0) printf(" ");
  }
  if (n >= 1000) {
    printf("%lld hajar", n / 1000);
    n %= 1000;
    if (n > 0) printf(" ");
  }
  if (n >= 100) {
    printf("%lld shata", n / 100);
    n %= 100;
    if (n > 0) printf(" ");
  }
  if (n != 0) printf("%lld", n);
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  ll n;
  while (scanf("%lld", &n) != EOF)
  {
    printf("%4d. ", t);
    if (n == 0) printf("%lld", n);
    else solve(n);
    printf("\n");
    t++;
  }
  return 0;
}

