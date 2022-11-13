#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

// ref: https://japlslounge.com/posts/cses/two_knights/1.htm

void solve()
{
  ll n; cin >> n;
  cout << 0 << endl;
  for (ll i = 2; i <= n; i++) {
    cout << i * i * (i * i - 1) / 2ll - 4 * (i - 1) * (i - 2) << endl;
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

