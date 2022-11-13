#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

const int mxn = 2e5 + 5;

int n, q, st[mxn][21];

void init() {
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j <= n; j++) {
      st[j][i] = st[st[j][i - 1]][i - 1];
    }
  }
}

void solve()
{
  cin >> n >> q;
  for (int i = 2; i <= n; i++) cin >> st[i][0];
  init();
  while (q--) {
    int x, k;
    cin >> x >> k;
    for (int i = 0; i < 20; i++) {
      if (k & (1 << i)) {
        x = st[x][i];
      }
    }
    if (!x) cout << "-1\n";
    else cout << x << endl;
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

