#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1e5 + 5;
ll dp[mxn], cnt[mxn];

void solve()
{
  int n; cin >> n;
  int max_val = -1;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    max_val = max(max_val, x);
    cnt[x]++;
  }

  dp[0] = 0ll;
  dp[1] = cnt[1];
  for (int i = 2; i <= max_val; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
  }
  cout << dp[max_val] << endl;
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

