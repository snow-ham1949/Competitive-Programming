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
  string s, t;
  cin >> s >> t;
  int n = SZ(s), m = SZ(t);
  if (s[n - 1] == t[m - 1]) {
    if (n == m) cout << "=\n";
    else if (n < m) {
      if (s[n - 1] == 'L') cout << "<\n";
      else cout << ">\n";
    }
    else {
      if (s[n - 1] == 'L') cout << ">\n";
      else cout << "<\n";
    }
  }
  else if ((s[n - 1] == 'S' and t[m - 1] == 'M') ||
           (s[n - 1] == 'M' and t[m - 1] == 'L') ||
           (s[n - 1] == 'S' and t[m - 1] == 'L')) {
    cout << "<\n";
  }
  else if ((s[n - 1] == 'M' and t[m - 1] == 'S') ||
            (s[n - 1] == 'L' and t[m - 1] == 'M') ||
            (s[n - 1] == 'L' and t[m - 1] == 'S')) {
              cout << ">\n";
  }
  return;
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

