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
  vector<pii> customers;
  for (int i = 0, s, t; i < n; i++) {
    cin >> s >> t;
    customers.push_back({s, 1});
    customers.push_back({t, -1});
  }
  sort(customers.begin(), customers.end());
  int cur = 0, mx = 0;
  for (const auto &c : customers) {
    cur += c.Y;
    mx = max(mx, cur);
  }
  cout << mx << endl;
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

