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
  int money = 0, month = 0, cost = 0, save = 0;
  for (int i = 1; i <= 12; i++) {
    money += 300;
    cin >> cost;
    money -= cost;
    if (money < 0) {
      month = i;
      break;
    }
    save += money / 100;
    money %= 100;
  }

  if (month) cout << -month << endl;
  else cout << save * 120 + money << endl;
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

