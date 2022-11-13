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
  ll n; cin >> n;
  ll tot = n * (n + 1) / 2ll;
  if (tot & 1) {
    cout << "NO\n";
    return;
  } else {
    vector<int> v1, v2;
    tot >>= 1;
    while (n) {
      if (tot - n >= 0) {
        v1.push_back(n);
        tot -= n;
      }
      else {
        v2.push_back(n);
      }
      n--;
    }
    cout << "YES\n";
    cout << SZ(v1) << endl;
    for (auto x : v1) cout << x << " ";
    cout << endl;
    cout << SZ(v2) << endl;
    for (auto x : v2) cout << x << " ";
    cout << endl;
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

