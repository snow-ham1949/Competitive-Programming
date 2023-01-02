#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

void solve()
{
  int n; cin >> n;
  vector<pii> v;
  for (int i = 0, a, b; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, 1});
    v.push_back({a + b, -1});
  }
  sort(v.begin(), v.end());

  int cnt = 0;
  vector<int> ans(n + 5, 0);
  for (int i = 0; i < SZ(v) - 1; i++) {
    cnt += v[i].Y;
    ans[cnt] += (v[i + 1].X - v[i].X);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i + 1] << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

