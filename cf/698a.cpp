#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 100 + 5;
int a[mxn], dp[mxn][3];

// dp[i][0]: have rest
// dp[i][1]: participate in contest
// dp[i][2]: go to gym
// dp[i][j]: max days that she doesn't have a rest day after ith day passed, doing rest/contest/gym

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i = 1; i <= n; i++) {
    dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    if (a[i] == 2 || a[i] == 3) { // gym is open
      dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
    }
    if (a[i] == 1 || a[i] == 3) { // participate in contest
      dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
    }
  }

  int maxx = max({dp[n][0], dp[n][1], dp[n][2]});
  cout << n - maxx << endl;
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

