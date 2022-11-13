#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

void solve()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;

  vector<int> dp(n);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = a[i];
    if (i + a[i] < n) {
      dp[i] += dp[i + a[i]];
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
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

