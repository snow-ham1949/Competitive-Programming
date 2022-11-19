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
  vector<int> p(n);
  for (int &x : p) cin >> x;
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cnt[(p[i] - 1 - i + j + n) % n]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(cnt[i], ans);
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

