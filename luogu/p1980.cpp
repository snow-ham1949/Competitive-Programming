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
  int n, x, cnt = 0;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    int sz = SZ(s);
    for (int j = 0; j < sz; j++) {
      if (s[j] - '0' == x) cnt++;
    }
  }
  cout << cnt << endl;
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

