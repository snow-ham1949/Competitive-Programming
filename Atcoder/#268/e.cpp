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
ll a[mxn];
int n;

int loop(int x) {
  return (x % n + n) % n;
}

ll dist(int x, int y) {
  int d = abs(x - y);
  return min(d, n - d);
}

void add(int l, int r, int k) {
  l = loop(l), r = loop(r);
  if (l <= r) {
    a[l] += k;
    a[r + 1] -= k;
  }
  else {
    a[l] += k;
    a[0] += k;
    a[r + 1] -= k;
  }
}

void solve()
{
  cin >> n;
  ll sum = 0;
  int k = n / 2;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    x -= i;
    add(x + 1, x + k, 1);
    add(x - k + 1, x, -1);
    sum += dist(x, 0);
  }
  ll ans = sum;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    sum += a[i];
    ans = min(ans, sum);
  }
  cout << ans << endl;
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

