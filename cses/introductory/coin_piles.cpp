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
  ll a, b; cin >> a >> b;
  if ((2 * b - a) % 3 != 0 || (2 * a - b) % 3 != 0) cout << "NO\n";
  else if (2 * b - a < 0 || 2 * a - b < 0) cout << "NO\n";
  else cout << "YES\n";
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

