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
  map<string, int> mp;
  double cnt = 0;
  string s;
  while (getline(cin, s) && s != "") {
    mp[s]++;
    cnt++;
  }
  
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->X << " " << fixed << setprecision(4) << it->Y / cnt * 100 << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  cin.get();
  string s;
  getline(cin, s);
  while (t--)
  {
    solve();
    if (t) cout << "\n";
  }
  return 0;
}

