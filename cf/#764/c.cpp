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
  int n; cin >> n;
  vector<int> v(n);
  vector<int> vis(n + 5, 0);
  vector<int> unused;
  for (int &x : v) {
    cin >> x;
    if (x <= n && !vis[x]) vis[x] = 1;
    else unused.push_back(x);
  }
  sort(unused.begin(), unused.end());
  for (int x : unused) {
    bool flag = 0;
    x /= 2;
    while (x) {
      if (x <= n && !vis[x]) {
        vis[x] = 1;
        flag = 1;
        break;
      }
      x /= 2;
    }
    if (!flag) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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

