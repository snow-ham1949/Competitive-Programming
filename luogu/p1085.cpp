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
  int day = 0, maxx = -1;
  for (int i = 1; i <= 7; i++) {
    int a, b; cin >> a >> b;
    if (a + b > 8) {
      if (a + b > maxx) {
        maxx = a + b;
        day = i;
      }
    }
  }
  cout << day << endl;
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

