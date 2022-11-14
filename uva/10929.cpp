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
  string s; 
  while (cin >> s) {
    if (s == "0") break;
    int odd = 0, even = 0;
    for (int i = 0; s[i]; i++) {
      if (i & 1) even += (s[i] - '0');
      else odd += (s[i] - '0');
    }
    if (abs(odd - even) % 11 == 0) cout << s << " is a multiple of 11.\n";
    else cout << s << " is not a multiple of 11.\n";
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

