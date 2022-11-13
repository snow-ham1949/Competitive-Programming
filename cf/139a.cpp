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
  vector<int> read(7);
  for (int &i : read) cin >> i;
  int num = 0, day = 0;
  while (num < n) {
    num += read[day];
    if (num >= n) {
      cout << day + 1 << endl;
      return;
    }
    day = (day + 1) % 7;
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

