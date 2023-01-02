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
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "Yes\n";
    return;
  }
  for (int i = 0; i < SZ(s); i++) {
    if (s[i] != t[i]) {
      if (i > 0) {
        swap(s[i - 1], s[i]);
        if (s == t) {
          cout << "Yes\n";
          return;
        }
        swap(s[i - 1], s[i]);
      }
      if (i + 1 < SZ(s)) {
        swap(s[i], s[i + 1]);
        if (s == t) {
          cout << "Yes\n";
          return;
        }
        swap(s[i], s[i + 1]);
      }
      break;
    }
  }
  cout << "No\n";
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

