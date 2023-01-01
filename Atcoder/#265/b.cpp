#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 1e5 + 5;
int A[mxn], bonus[mxn];

void solve()
{
  int n, m; cin >> n >> m;
  ll t; cin >> t;
  for (int i = 1; i < n; i++) cin >> A[i];
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    bonus[x] = y;
  }
  for (int i = 1; i < n; i++) {
    if (t <= A[i]) {
      cout << "No\n";
      return;
    }
    t -= A[i];
    t += bonus[i + 1];
  }
  cout << "Yes\n";
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

