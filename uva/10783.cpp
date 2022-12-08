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
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (i & 1) ans += i;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    cout << "Case " << i << ": ";
    solve(); 
  }
  return 0;
}

