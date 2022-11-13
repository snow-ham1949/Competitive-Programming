#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 1000 + 5;

int a[mxn][mxn], pre[mxn][mxn];

void solve()
{
  int n, q;
  cin >> n >> q;
  char ch;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> ch;
      if (ch == '.') a[i][j] = 0;
      else a[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pre[i][j] = a[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
    }
  }

  int x1, x2, y1, y2;
  while (q--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1] << endl;
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

