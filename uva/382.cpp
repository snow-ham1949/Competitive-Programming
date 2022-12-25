#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

void solve()
{
  printf("PERFECTION OUTPUT\n");
  int n;
  while (scanf("%d", &n) && n != 0) {
    if (n == 1) {
      printf("    1  DEFICIENT\n");
      continue;
    }
    vector<int> v;
    v.push_back(1);
    for (int i = 2; i * i <= n; i++) {
      if (i * i == n) v.push_back(i);
      else if (n % i == 0) {
        v.push_back(n / i);
        v.push_back(i);
      }
    }
    int res = 0;
    for (int x : v) res += x;
    if (res == n) printf("%5d  PERFECT\n", n);
    else if (res < n) printf("%5d  DEFICIENT\n", n);
    else printf("%5d  ABUNDANT\n", n);
  }
  printf("END OF OUTPUT\n");
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

