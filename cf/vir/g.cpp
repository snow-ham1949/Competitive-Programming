#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

vector<tuple<int, int, int>> v;

void solve()
{
  int n; cin >> n;
  for (int i = 0, a, b; i < 2 * n; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    v.emplace_back(a + b, a, b);
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) ans -= get<1>(v[i]);
  for (int i = n; i < 2 * n; i++) ans += get<2>(v[i]);
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

