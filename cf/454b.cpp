#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1e5 + 5;
int a[mxn];

void solve()
{
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0, res = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) {
      sum++;
      res = n - i;
    }
  }
  if (sum == 0) cout << "0\n";
  else if (sum > 1) cout << "-1\n";
  else {
    if (a[0] >= a[n - 1]) cout << res << endl;
    else cout << "-1\n";
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

