#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
int a[mxn];
map<int, int> mp;

void solve()
{
  int n, x; cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (mp.count(x - a[i])) {
      cout << i + 1 << " " << mp[x - a[i]] << endl;
      return;
    }
    mp[a[i]] = i + 1;
  }
  cout << "IMPOSSIBLE\n";
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

