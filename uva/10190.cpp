#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

#define eb emplace_back
int n, m;
string boring = "Boring!\n";

void solve()
{
  if (n <= 1 || m <= 1) {
    cout << boring;
    return;
  }
  vector<int> v;
  while (n % m == 0) {
    v.eb(n);
    n /= m;
  }
  if (n != 1) {
    cout << boring;
    return;
  }
  for (int x : v) cout << x << " ";
  cout << "1\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (cin >> n >> m)
  {
    solve(); 
  }
  return 0;
}

