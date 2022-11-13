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
  int num = -1;
  for (int i = 1; i <= 14142; i++) {
    if (n <= i * (i + 1) / 2) {
      num = i;
      break;
    }
  }
  if (n == num * (num + 1) / 2) {
    if (num & 1) cout << "1/" << num << endl;
    else cout << num << "/1" << endl;
  }
  else {
    n -= (num - 1) * num / 2;
    if (num & 1) cout << num + 1 - n << "/" << n << endl;
    else cout << n << "/" << num + 1 - n << endl;
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

