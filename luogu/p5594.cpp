#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

set<int> s[1005];

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)  {
    for (int j = 1; j <= m; j++) {
      int x; cin >> x;
      s[x].insert(j);
    }
  }
  for (int i = 1; i <= k; i++) cout << SZ(s[i]) << " ";
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

