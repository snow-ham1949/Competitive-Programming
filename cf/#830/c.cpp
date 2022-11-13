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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 5), pre(n + 5), xorr(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
    if (i == 1) {
      xorr[i] = a[i];
    } else {
      xorr[i] = xorr[i - 1] ^ a[i];
    }
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

