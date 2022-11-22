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
  vector<int> v(n + 1);
  for (int i = 0; i < n; i++) cin >> v[i];
  v[n] = 1000000005;
  int l = 0, r = 0, cnt = 0;
  while (r < n) {
    //cerr << "before process, l: " << l << " " << ",r: " << r << endl;
    while (r < n && v[l] == v[r]) r++;
    r--;
    //cerr << "after  process, l: " << l << " " << ",r: " << r << endl;
    if ((l == 0 || (v[l - 1] > v[l])) && (r == n - 1 || (v[r] < v[r + 1]))) {
      //cerr << l << " " << r << endl;
      cnt++;
    }
    r++;
    l = r;
  }
  if (cnt == 1) cout << "Yes\n";
  else cout << "No\n";
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

