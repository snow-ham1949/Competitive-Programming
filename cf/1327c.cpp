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
  int n, m; cin >> n >> m;
  string ans = "";
  ans.append(n - 1, 'U');
  ans.append(m - 1, 'L');
  for (int i = 0; i < n; i++) {
    if (i % 2) ans.append(m - 1, 'L');
    else ans.append(m - 1, 'R');
    if (i != n - 1)ans.append("D");
  }
  cout << ans.length() << endl << ans << endl;
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

