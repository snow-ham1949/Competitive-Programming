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
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int &x : v) cin >> x;
    sort(v.begin(), v.end());
    int mid1 = v[(n - 1) / 2], mid2 = v[n / 2], cnt = 0;
    for (int x : v) {
      if (x == mid1 || x == mid2) cnt++;
    }
    cout << mid1 << " " << cnt << " " << mid2 - mid1 + 1 << endl;
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

