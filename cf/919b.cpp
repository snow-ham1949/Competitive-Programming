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
  vector<int> v;
  for (int i = 19; i <= 11000000; i++) {
    string s = to_string(i);
    int sum = 0;
    for (auto ch : s) {
      sum += (ch - '0');
    }
    if (sum == 10) v.push_back(i);
  }
  //cerr << "sz: " << SZ(v) << endl;
  int n; cin >> n;
  cout << v[n - 1] << endl;
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

