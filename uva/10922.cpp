#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int degree(string s) {
  int deg = 0;
  if (s == "9") return 1;
  while (SZ(s) >= 2) {
    int n = 0;
    for (int i = 0; s[i]; i++) {
      n += (s[i] - '0');
    }
    if (n % 9 == 0) deg++;
    s = to_string(n);
  }
  return deg;
}

string s;
void solve()
{
  int deg = degree(s);
  if (deg) {
    cout << s << " is a multiple of 9 and has 9-degree " << deg << ".\n";
  }
  else cout << s << " is not a multiple of 9.\n";
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (cin >> s && s != "0")
  {
    solve(); 
  }
  return 0;
}

