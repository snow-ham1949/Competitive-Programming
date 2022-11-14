#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

bool cmp(pair<int, char> a, pair<int, char> b) {
  if (a.X != b.X) {
    return a.X > b.X;
  }
  else {
    return a.Y < b.Y;
  }
}
void solve()
{
  int n; cin >> n;
  string s;
  getline(cin, s);
  map<char, int> mp;
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    for (int j = 0; s[j]; j++) {
      if (s[j] >= 'a' && s[j] <= 'z') {
        mp[toupper(s[j])]++;
      } else if (s[j] >= 'A' && s[j] <= 'Z') {
        mp[s[j]]++;
      }
    }
  }
  
  vector<pair<int, char>> v;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    v.push_back({it->Y, it->X});
  }
  sort(v.begin(), v.end(), cmp);
  for (auto [x, c] : v) {
    cout << c << " " << x << endl;
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

