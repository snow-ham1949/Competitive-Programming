#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
int a[mxn];
int n;

int dp(int id, ll h, int green, int blue) {
  if (id == n) return 0;
  if (a[id] < h) 
    return dp(id + 1, h + (a[id] / 2), green, blue) + 1;
  int ans1 = (green ? dp(id, h * 2, green - 1, blue) : 0);
  int ans2 = (blue ? dp(id, h * 3, green, blue - 1) : 0);
  return max(ans1, ans2);
}

void solve()
{
  ll h;
  cin >> n >> h;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << dp(0, h, 2, 1) << endl;
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

