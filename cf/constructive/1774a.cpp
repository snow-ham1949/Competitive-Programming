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
  int n; cin >> n;
  string s; cin >> s;
  string res = "";
  int is_one = (s[0] == '1' ? 1 : 0);
  for (int i = 1; i < n; i++) {
    if (s[i] == '0') res += "-";
    else {
      if (is_one) res += "-";
      else res += "+";      
      is_one ^= 1;
    }
  }
  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--)
  {
    solve(); 
  }
  return 0;
}

