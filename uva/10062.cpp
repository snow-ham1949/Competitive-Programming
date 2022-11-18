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
  string s;
  int cnt = 0;
  while (getline(cin, s)) {
    if (cnt > 0) cout << endl;
    cnt++;
    map<char, int> mp;
    for (char ch : s) mp[ch]++;
    vector<pii> v;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      v.push_back({it->Y, (int)it->X});
    }
    sort(v.begin(), v.end(), [](pii a, pii b) {
      return a.X == b.X ? a.Y > b.Y : a.X < b.X;
    });
    for (auto [f, c]: v) {
      cout << c << " " << f << endl;
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

