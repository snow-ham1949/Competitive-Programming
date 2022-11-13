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
  int n, m; cin >> n >> m;
  if (!(n & 1) && (m & 1)) {
    cout << min(n / 2 * m, (m - 1) / 2 * n + n / 2) << endl;
  } else if (!(n & 1) && !(m & 1)) {
    cout << n * m / 2 << endl;
  } else if (n & 1 && !(m & 1)) {
    cout << min(n * m / 2, (n - 1) / 2 * m + m / 2) << endl;
  } else {
    cout << min((m - 1) / 2 * n + (n + 1) / 2, (n - 1) / 2 * m + (m + 1) / 2) << endl;
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

