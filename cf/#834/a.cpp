#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

string ans;

void init() {
  for (int i = 0; i <= 18; i++) {
    ans = ans + "Yes";
  }
}

void solve()
{
  string s;
  cin >> s;
  int n = SZ(s);
  for (int i = 0; i < 51; i++) {
    if (ans.substr(i, n) == s) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  init();
  while (t--)
  {
    solve(); 
  }
  return 0;
}
