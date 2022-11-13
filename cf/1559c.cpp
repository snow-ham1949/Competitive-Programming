#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1e4 + 5;
int a[mxn];

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int l = -1, r;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == 0 and a[i + 1] == 1) {
      l = i; r = l + 1;
      break;
    }
  }
  if (l != -1) {
    for (int i = 1; i < l; i++) {
      cout << i << " ";
    }
    cout << l << " " << n + 1 << " " << r << " ";
    for (int i = r + 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }
  if (a[n] == 0) {
    for (int i = 1; i <= n + 1; i++) cout << i << " ";
    cout << endl;
    return;
  }
  if (a[1] == 1) {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    return;
  }
  cout << "-1\n";
  memset(a, 0, sizeof(a));
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

