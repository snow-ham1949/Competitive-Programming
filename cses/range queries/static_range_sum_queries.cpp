#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;

ll a[mxn], pre[mxn];

void solve()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;
    cout << pre[y] - pre[x - 1] << endl;
  }
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

