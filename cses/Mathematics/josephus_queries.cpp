#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int f(int n, int k) {
  if (n == 1) return 1;
  int kill = (n + 1) / 2;
  if (k <= kill) {
    if (2 * k > n) return 2 * k % n;
    return 2 * k;
  }
  int tmp = f(n >> 1, k - kill);
  if (n & 1) return 2 * tmp + 1;
  return 2 * tmp - 1;
}

void solve()
{
  int n, k; cin >> n >> k;
  cout << f(n, k) << endl;
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

