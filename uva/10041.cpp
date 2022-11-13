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
  int r; cin >> r;
  vector<int> s(r);
  for (int &x : s) cin >> x;
  int m = r / 2, dis = 0;
  sort(s.begin(), s.end());
  for (int i = 0; i < r; i++) {
    dis += abs(s[m] - s[i]);
  }
  cout << dis << endl;
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

