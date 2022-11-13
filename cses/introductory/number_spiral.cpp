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
  ll x, y; cin >> x >> y;
  if (x < y) {
    if (y & 1) {
      cout << y * y - x + 1 << endl;
    }
    else {
      cout << (y - 1) * (y - 1) + 1 + x - 1 << endl;
    }
  } 
  else {
    if (x & 1) {
      cout << (x - 1) * (x - 1) + 1 + y - 1 << endl;
    }
    else {
      cout << x * x - y + 1 << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

