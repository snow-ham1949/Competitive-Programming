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
  vector<ll> a(n);
  for (ll &i : a) cin >> i;
  sort(a.begin(), a.end());
  ll missing = 1;
  for (int i = 0; i < n && a[i] <= missing; i++) {
    missing += a[i];
  }
  cout << missing << endl;
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

