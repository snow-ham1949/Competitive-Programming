#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int dp[200 + 5][6 + 5]; // dp[i][j] := 把 i 分成 j 個正整數

void solve()
{
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    dp[i][0] = 1;
  }
  for (int i = 2; i <= k; i++) {
    dp[1][i] = 0;
    dp[0][i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      dp[i][j] = dp[i - 1][j - 1];
      if (i > j) {
        dp[i][j] += dp[i - j][j];
      }
    }
  }
  cout << dp[n][k] << endl;
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

