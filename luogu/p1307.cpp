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
  int n; cin >> n;
  int x = 0;
  if (n < 0) {
    n *= -1;
    while (n) {
      x = x * 10 + n % 10;
      n /= 10;
    }
    cout << x * -1 << endl;
  }
  else {
    while (n) {
      x = x * 10 + n % 10;
      n /= 10;
    }
    cout << x << endl;
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

