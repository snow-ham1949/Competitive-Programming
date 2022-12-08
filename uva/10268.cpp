#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

ll x;
string s;
vector<ll> v;

void solve()
{
  v.clear();
  stringstream ss(s);
  while (ss >> s) {
    v.push_back(stoll(s));
  }
  v.pop_back();
  ll ans = 0;
  ll n = SZ(v), co = 1LL, val = 1LL; // coefficient
  for (int i = n - 1; i >= 0; i--) {
    ans += co * v[i] * val;
    val *= x;
    co++;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  // int t = 1;
  // cin >> t;
  while (cin >> x)
  {
    getline(cin, s);
    getline(cin, s);
    solve(); 
  }
  return 0;
}
