#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mod = 100003;
int dp[100000 + 5];

void solve()
{
  int n, k; cin >> n >> k;
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i >= j) dp[i] = dp[i] + dp[i - j] % mod;
    }
  }
  //for (int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];
  cout << dp[n] % mod << endl;
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

