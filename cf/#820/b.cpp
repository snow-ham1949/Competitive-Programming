#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
  int n; cin >> n;
  string s; cin >> s;
  string ans = "";
  int ptr = n - 1;
  while (ptr >= 0)
  {
    if (s[ptr] == '0') {
      ans += ((s[ptr - 2] - '0') * 10 + s[ptr - 1] - '0' + 'a' - 1);
      ptr -= 3;
    } else {
      ans += ('a' + s[ptr] - '0' - 1);
      ptr--;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

