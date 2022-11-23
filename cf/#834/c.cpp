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
  ll l, r, x, a, b;
  cin >> l >> r >> x >> a >> b;
  if (a == b) cout << "0\n";
  else if (abs(a - b) >= x) cout << "1\n";
  else if ((a - l >= x && b - l >= x) || (r - a >= x && r - b >= x)) cout << "2\n";
  else if ((a - l >= x && r - l >= x && r - b >= x) || (r - a >= x && r - l >= x && b - l >= x)) cout << "3\n";
  else cout << "-1\n";
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

