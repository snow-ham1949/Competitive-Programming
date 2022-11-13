#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
  int n; cin >> n;
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  int maxx = max_element(v.begin(), v.end()) - v.begin() + 1;
  cout << maxx << endl;
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

