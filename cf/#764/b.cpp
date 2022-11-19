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
  ll a, b, c;
  cin >> a >> b >> c;
  if (2 * b == a + c) {
    cout << "Yes\n";
  }
  else {
    if (2 * b < a + c) {
      if ((a + c) % (2 * b) == 0) cout << "Yes\n";
      else cout << "No\n";
    }
    else {
      if ((2 * b - c) % a == 0 || (2 * b - a) % c == 0) cout << "Yes\n";
      else cout << "No\n";
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

