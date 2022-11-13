#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 100 + 6;
ll dis[mxn][mxn];
int n, m;

void Floyd()
{
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

void solve()
{
  cin >> n >> m;
  vector<int> a(m);
  for (auto &i : a) cin >> i;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> dis[i][j];
    }
  }
  Floyd();
  ll ans = 0;
  for (int i = 1; i < m; i++)
  {
    ans += dis[a[i - 1]][a[i]];
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

