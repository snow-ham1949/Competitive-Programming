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
  double need; cin >> need;
  pair<double, int> a[3];
  for (int i = 0; i < 3; i++) {
    cin >> a[i].X >> a[i].Y;
  }
  int ans = INT_MAX;
  for (int i = 0; i < 3; i++) {
    int pack = ceil(need / a[i].X);
    ans = min(ans, pack * a[i].Y);
  }
  cout << ans << endl;
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

