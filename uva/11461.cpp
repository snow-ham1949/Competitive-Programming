#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int a, b;

void solve()
{
  int ans = 0;
  for (int i = a; i <= b; i++) {
    int x = sqrt(i);
    if (x * x == i) ans++;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  while (cin >> a >> b)
  {
    if (a == 0 && b == 0) break;
    solve(); 
  }
  return 0;
}

