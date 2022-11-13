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
  vector<string> v;
#define eb emplace_back
  v.eb("0");
  v.eb("1");
  for (int i = 2; i < (1 << n); i <<= 1) {
    for (int j = i - 1; j >= 0; j--) {
      v.eb(v[j]);
    }
    for (int j = 0; j < i; j++) {
      v[j] = "0" + v[j];
    }
    for (int j = i ; j < 2 * i; j++) {
      v[j] = "1" + v[j];
    }
  }
  for (auto s : v) {
    cout << s << endl;
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

