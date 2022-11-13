#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

int coins[5] = {1, 5, 10, 20, 100};

void solve()
{
  int n; cin >> n;
  int cnt = 0;
  for (int i = 4; i >= 0; i--) {
    cnt += n / coins[i];
    n %= coins[i];
  }
  cout << cnt << endl;
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

