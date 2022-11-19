#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int ask(int c) {
  cout << "+ " << c << endl;
  int ans; cin >> ans;
  return ans;
}

void solve()
{
  int n; cin >> n;
  int l = 1, r = n, q = 0;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    int d = ask(n - mid);
    if (d > q) l = mid;
    else r = mid;

    l = (l + n - mid) % n;
    r = (r + n - mid) % n;

    if (r == 0) r = n;
    q = d;
  }
  cout << "! " << q * n + l << endl;
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

