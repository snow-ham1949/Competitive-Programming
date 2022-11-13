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
 int q; cin >> q;
 char op;
 ll x;
 map<ll, ll> vis;
 map<ll, ll> last;
 while (q--) {
  cin >> op >> x;
  if (op == '+') vis[x] = 1;
  else {
    if (!last.count(x)) last[x] = x;
    while (vis[last[x]]) last[x] += x;
    cout << last[x] << endl;
  }
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

