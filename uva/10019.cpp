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
  bitset<16> x1(n);
  int b1 = x1.count();
  int m = 0;
  string s = to_string(n);
  for (int i = 0; s[i]; i++) {
    m *= 16;
    m += (s[i] - '0');
  }
  bitset<16> x2(m);
  int b2 = x2.count();
  cout << b1 << " " << b2 << "\n";
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

