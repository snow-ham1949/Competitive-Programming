#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int n;

void solve()
{
  int cnt = 0;
  string s = "";
  while (n) {
    if (n & 1) {
      s = "1" + s;
      cnt++;
    }
    else s = "0" + s;
    n >>= 1;
  }
  
  printf("The parity of %s is %d (mod 2).\n", s.c_str(), cnt);
}

int main() {
  // ios::sync_with_stdio(0);cin.tie(0);
  // int t = 1;
  // cin >> t;
  while (scanf("%d", &n) && n != 0)
  {
    solve(); 
  }
  return 0;
}

