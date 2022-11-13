#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

void solve()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  if (a[0] > a[n - 1]) cout << "NO\n";
  else cout << "YES\n";
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

