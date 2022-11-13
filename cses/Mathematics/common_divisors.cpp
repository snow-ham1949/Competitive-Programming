#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxv = 1e6;
int cnt[mxv + 5];

void solve()
{
  int n; cin >> n;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    cnt[x]++;
  }

  for (int gcd = mxv; gcd > 0; gcd--) {
    int mul = 0; // multiple of gcd
    for (int j = gcd; j <= mxv; j += gcd) {
      mul += cnt[j];
    }
    if (mul >= 2) {
      cout << gcd << endl;
      return;
    }
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

