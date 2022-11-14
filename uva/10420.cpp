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
  int n; cin >> n;
  string s, tmp;
  for (int i = 0; i < n; i++) {
    cin >> s;
    mp[s]++;
    getline(cin, tmp);
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->X << " " << it->Y << endl;
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
