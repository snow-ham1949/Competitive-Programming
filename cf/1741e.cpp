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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<bool> dp(n + 1, false);
  dp[0] = true;
  for (int i = 1; i <= n; i++) {
    // segment is on it's right
    if (i + a[i] <= n && dp[i - 1]) dp[i + a[i]] = true;
    // segment is on it's left
    if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) dp[i] = true;
  }
  cout << (dp[n] ? "YES" : "NO") << endl;
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

