#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int ans[15];

bool joseph(int n, int k) {
  int pos = 0;
  for (int i = 2 * n; i > n; i--) {
    pos = (pos - 1 + k) % i;
    if (pos < n) return false;
  }
  return true;
}

int solve(int n)
{
  for (int j = n + 1; ; j++) {
    if (joseph(n, j)) return j;
  }
}

void init() {
  for (int i = 1; i <= 14; i++) {
    ans[i] = solve(i);
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  init();
  int k;
  while (cin >> k && k != 0)
  {
    cout << ans[k] << "\n";
  }
  return 0;
}

