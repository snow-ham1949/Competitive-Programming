#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 10 + 5;
int a[mxn][mxn], b[mxn][mxn];

void solve()
{
  int h1, w1; cin >> h1 >> w1;
  for (int i = 0; i < h1; i++) {
    for (int j = 0; j < w1; j++) {
      cin >> a[i][j];
    }
  }
  int h2, w2; cin >> h2 >> w2;
  for (int i = 0; i < h2; i++) {
    for (int j = 0; j < w2; j++) {
      cin >> b[i][j];
    }
  }

  bool match = false;
  for (int i = 0; i < (1 << h1); i++) {
    for (int j = 0; j < (1 << w1); j++) {
      vector<int> h, w;
      for (int k = 0; k < h1; k++) if (i & (1 << k)) h.push_back(k);
      for (int k = 0; k < w1; k++) if (j & (1 << k)) w.push_back(k);
      if (SZ(h) != h2 || SZ(w) != w2) continue;

      match = true;
      for (int k = 0; k < h2; k++) {
        for (int l = 0; l < w2; l++) {
          if (a[h[k]][w[l]] != b[k][l]) {
            match = false;
            break;
          }
        }
      }
      if (match) {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--)
  {
    solve(); 
  }
  return 0;
}

