#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

void solve()
{
  vector<int> mxh(10000 + 5, 0);
  int mxr = 0;
  int l, r, h;
  while (cin >> l >> h >> r) {
    for (int i = l; i < r; i++) {
      mxh[i] = max(mxh[i], h);
    }
    mxr = max(mxr, r); 
  }
  
  int flag = 0;
  for (int x = 1; x <= mxr; x++) {
    if (mxh[x] != mxh[x - 1]) {
      if (flag) cout << " ";
      flag = 1;
      cout << x << " " << mxh[x];
    }
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

