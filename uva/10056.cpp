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
  int n, x;
  long double p, q, ans;
  cin >> n >> p >> x;
  q = 1.0 - p;
  if (q == 1) {
    cout << "0.0000\n";
    return;
  }
  ans = p * pow(q, x - 1) / (1.0 - pow(q, n));
  cout << fixed << setprecision(4) << ans << "\n";
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

