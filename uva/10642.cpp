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
  int sx, sy, tx, ty;
  cin >> sy >> sx >> ty >> tx; 
  ll s = (sx + sy) * (sx + sy + 1LL) / 2LL + sy;
  ll t = (tx + ty) * (tx + ty + 1LL) / 2LL + ty;
  cout << t - s << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cout << "Case " << i << ": ";
    solve(); 
  }
  return 0;
}

