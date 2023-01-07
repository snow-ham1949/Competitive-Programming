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
  int n; cin >> n;
  vector<string> v(n);
  for (auto &s : v) cin >> s;
  for (int i = n - 1; i >= 0; i--) {
    cout << v[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--)
  {
    solve(); 
  }
  return 0;
}

