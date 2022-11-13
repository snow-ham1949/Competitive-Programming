#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int a[10 + 5];

void solve()
{
  for (int i = 0; i < 10; i++) cin >> a[i];
  int x, cnt = 0; cin >> x;
  for (int i = 0; i < 10; i++) {
    if (x + 30 >= a[i]) cnt++;
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

