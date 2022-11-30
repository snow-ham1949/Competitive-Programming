#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int n;
void solve()
{
  int g = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      g += __gcd(i, j);
    }
  }
  cout << g << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (cin >> n && n != 0)
  {
    solve(); 
  }
  return 0;
}

