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
  if (n == 1) {
    cout << "1\n";
  }
  else if (n == 2 || n == 3) {
    cout << "NO SOLUTION\n";
  }
  else if (n == 4) {
    cout << "2 4 1 3\n";
  }
  else {
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    for (int i = 2; i <= n; i += 2) {
      cout << i;
      if (i + 2 <= n) cout << " ";
      else cout << "\n";
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
