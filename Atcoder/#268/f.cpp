#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

#define tiii tuple<int, int, int>

void solve()
{
  int n; cin >> n;
  vector<tuple<int, int, int>> v;
  vector<string> str_v;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int cntx = 0, sum = 0;
    for (int j = 0; s[j]; j++) {
      if (s[j] == 'X') cntx++;
      else sum += (s[j] - '0');
    }
    v.push_back({cntx, sum, i});
    str_v.push_back(s);
  }

  sort(v.begin(), v.end(), [](tiii a, tiii b) {
    return (ll)get<0>(a) * (ll)get<1>(b) > (ll)get<1>(a) * (ll)get<0>(b);
  });
  
  string ans = "";
  for (int i = 0; i < n; i++) {
    ans += str_v[get<2>(v[i])];
  }
  
  ll sum = 0, cur = 0;
  for (int i = SZ(ans) - 1; i >= 0; i--) {
    if (ans[i] == 'X') sum += cur;
    else cur += (ll)ans[i] - '0';
  }
  cout << sum << endl;
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

