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
  vector<int> a(n);
  int res = 0;
  for (int &x: a) {
    cin >> x;
    res += (x & 1);
  }
  cout << res << '\n';
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

