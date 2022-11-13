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
  int n; cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (v[i] > v[i + 1] && v[i] > v[i - 1]) {
      ans++;
      if (i + 2 < n) {
        v[i + 1] = max(v[i], v[i + 2]);
      }
      else v[i + 1] = v[i];
    }
  }
  cout << ans << endl;
  for (int i : v) cout << i << " ";
  cout << endl;
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

