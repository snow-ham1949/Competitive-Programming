#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
int a[mxn], ind[mxn];

int check(int x, int y) {
  int sum = 0;
  if (ind[x - 1] > ind[x]) sum++;
  if (ind[x] > ind[x + 1]) sum++;
  if (ind[y - 1] > ind[y]) sum++;
  if (ind[y] > ind[y + 1]) sum++;
  if (x - y == 1 && ind[y] > ind[x]) sum--;
  if (y - x == 1 && ind[x] > ind[y]) sum--;
  return sum;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ind[a[i]] = i;
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    ans += (ind[i] > ind[i + 1]);
  }

  while (m--) {
    int x, y;
    cin >> x >> y;
    swap(a[x], a[y]);
    x = a[x], y = a[y];
    ans -= check(x, y);
    swap(ind[x], ind[y]);
    ans += check(x, y);
    cout << ans << endl;
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

