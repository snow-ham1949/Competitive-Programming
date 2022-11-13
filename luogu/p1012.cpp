#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

bool cmp(const string &a, const string &b) {
  return a + b > b + a;
}

void solve()
{
  int n; cin >> n;
  vector<string> v(n);
  for (auto &s : v) cin >> s;
  sort(v.begin(), v.end(), cmp);
  for (auto s : v) cout << s;
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

