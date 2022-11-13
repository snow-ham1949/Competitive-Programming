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
  double sum = 0.0, k = 0.0;
  cin >> k;
  double n = 1.0;
  while (sum <= k) {
    sum += 1.0/n;
    n += 1.0;
  }
  cout << int(n - 1.0) << endl;
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

