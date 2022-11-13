#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int) a.size()
#define endl '\n'
#define X first
#define Y second
int n;
long long int a[200005], b[200005];
long long int acc[200005];
void solve()
{
  cin >> n;
  for(int i=0; i<=n; ++i){
    cin >> a[i];
  }
  for(int i=0; i<=n; ++i){
    cin >> b[i];
  }
  ll ans = 0;
  for (int i = n; i > 0; i--) {
    int need = b[i] - a[i];
    if (need < 0) continue;
    need += 1;
    need >>= 1;
    b[i] -= need * 2;
    b[i - 1] += need;
    ans += need;
  }
  for (int i = 0; i < n; i++) {
    if (b[i] > a[i]) {
      cout << "-1\n";
      return;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
      solve();
  }
  return 0;
}

