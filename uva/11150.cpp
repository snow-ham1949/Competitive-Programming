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
  int n;
  while (cin >> n) {
    int ans = n, empty = n;
    while (empty >= 3) {
      ans += empty / 3;
      empty = empty / 3 + empty % 3;
    }
    if (empty == 2) ans++;
    cout << ans << "\n";
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

