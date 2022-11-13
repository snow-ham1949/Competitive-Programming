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
  for (int x = 123; x <= 329; x++) {
    vector<int> used(10, 0);
    int num = x;
    while (num) {
      used[num % 10]++;
      num /= 10;
    }
    int y = 2 * x, z = 3 * x;
    while (y) {
      used[y % 10]++;
      y /= 10;
    }
    while (z) {
      used[z % 10]++;
      z /= 10;
    }
    int flag = 1;
    for (int i = 1; i <= 9; i++) {
      if (used[i] == 0 || used[i] > 1) {
        flag = 0;
        break;
      }
    }
    if (flag) cout << x << " " << 2 * x << " " << 3 * x << endl;
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

