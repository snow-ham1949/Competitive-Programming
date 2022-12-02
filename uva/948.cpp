#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 40;
int fib[mxn + 5];

void init() {
  fib[1] = 1, fib[2] = 1;
  for (int i = 3; i <= mxn; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
}

void solve()
{
  int n; scanf("%d", &n);
  int id = -1;
  for (int i = mxn; i >= 1; i--) {
    if (n - fib[i] >= 0) {
      id = i;
      break;
    }
  }
  string s = "";
  int _n = n;
  for (int i = id; i >= 1; i--) {
    if (_n >= fib[i]) {
      _n -= fib[i];
      s += "1";
    }
    else {
      s += "0";
    }
  }
  s.pop_back();
  printf("%d = %s (fib)\n", n, s.c_str());
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  scanf("%d", &t);
  init();
  while (t--)
  {
    solve(); 
  }
  return 0;
}

