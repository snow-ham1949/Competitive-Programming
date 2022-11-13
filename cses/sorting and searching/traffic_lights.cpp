#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

set<int> lights;
multiset<int> dis;

void solve()
{
  int x, n; cin >> x >> n;
  dis.insert(x);
  lights.insert(0);
  lights.insert(x);
  
  int pos, l, r;
  while (n--) {
    cin >> pos;
    auto it = lights.upper_bound(pos);
    r = *it;
    l = *--it;
    lights.insert(pos);
    dis.erase(dis.find(r - l));
    dis.insert(r - pos);
    dis.insert(pos - l);
    cout << *--dis.end() << " ";
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

