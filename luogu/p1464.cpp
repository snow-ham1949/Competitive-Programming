#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

ll dp[25][25][25];

ll w(ll a,ll b,ll c)
{
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  else if (dp[a][b][c]) return dp[a][b][c];
  else if (a > 20 || b > 20 || c > 20) dp[a][b][c] = w(20, 20, 20);
  else if (a < b && b < c) dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  else dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return dp[a][b][c];
}

void solve()
{
  ll a,b,c;
  while(scanf("%lld%lld%lld",&a,&b,&c)==3){
    memset(dp,0,sizeof(dp));
    if(a == -1 && b == -1 && c== -1) break;
    printf("w(%lld, %lld, %lld) = ", a, b, c);
    if(a > 20) a = 21;
    if(b > 20) b = 21;
    if(c > 20) c = 21;
    printf("%lld\n", w(a, b, c));
  }
}

int main() {
  // ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

