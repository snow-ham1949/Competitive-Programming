#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

void solve()
{
  int m, n, q; cin >> m >> n >> q;
  cout << m << " " << n << " " << q << "\n";
  vector<string> g(m);
  for (string &s : g) cin >> s;
  while (q--) {
    int r, c;
    cin >> r >> c;
    char center = g[r][c];
    int mxh = min(r, m - r - 1), mxw = min(c, n - c - 1);
    int mx = min(mxh, mxw);
    int len = 0;
    int ok;
    for (int half = 1; half <= mx; half++) {
      ok = 1;
      for (int i = r - half; i <= r + half; i++) {
        for (int j = c - half; j <= c + half; j++) {
          if (g[i][j] != center) {
            ok = 0;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok) len++;
      else break;
    }

    cout << len * 2 + 1 << "\n";
  }
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

