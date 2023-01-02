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
  string s; cin >> s;
  sort(s.begin(), s.end());
  ll ans = 0;
  do {
    for (int i = 1; i < SZ(s); i++) {
      ll l = 0, r = 0;
      for (int j = 0; j < i; j++) l = l * 10 + (s[j] - '0');
      for (int j = i; j < SZ(s); j++) r = r * 10 + (s[j] - '0');
      ans = max(ans, l * r);
    }
  } while (next_permutation(s.begin(), s.end()));
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

