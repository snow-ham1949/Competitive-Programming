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
  int x; cin >> x;
  vector<int> v;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      if (i * i == x) v.push_back(i);
      else {
        v.push_back(x / i);
        v.push_back(i);
      }
    }
  }
  cout << SZ(v) << endl;
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

