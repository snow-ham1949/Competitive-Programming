#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

void solve()
{
  int n; cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    if (mp.count(s)) {
      string append = to_string(mp[s]);
      mp[s]++;
      s = s + append;
      cout << s << endl;
    } else {
      cout << "OK\n";
      mp[s]++;
    }
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

