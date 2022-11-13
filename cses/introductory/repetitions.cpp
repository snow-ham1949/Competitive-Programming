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
  string s; cin >> s;
  int n = SZ(s);
  int ans = 1;
  int l = 0, r = 0;
  while (r < n) {
    while (s[r] == s[l]) r++;
    ans = max(ans, r - l);
    l = r;
  }
  ans = max(ans, r - l);
  cout << ans << endl;
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
