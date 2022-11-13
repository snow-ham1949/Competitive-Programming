#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 5e6 + 6;
int fib[mxn];

void solve()
{
  int m; cin >> m;
  fib[0] = 0, fib[1] = 1;
  for (int i = 2; i < mxn; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % m;
    if (fib[i] == 1 && fib[i - 1] == 0) {
      cout << i - 1 << endl;
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

