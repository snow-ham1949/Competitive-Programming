#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

typedef tuple<ll, ll, ll> tlll;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (string &s: v) cin >> s;
  string s; cin >> s;
  map<string, tlll> mp;
  for (int j = 0; j < n; j++) {
    string x = v[j];
    for (int i = 0; i < m - 2; i++) {
      mp[x.substr(i, 3)] = {i, i + 2, j};
    }
  }
  for (int j = 0; j < n; j++) {
    string x = v[j];
    for (int i = 0; i < m - 1; i++) {
      mp[x.substr(i, 2)] = {i, i + 1, j};
    }
  }
  vector<int> dp(m + 1, -1);
  dp[m] = m;

  for (int i = m - 1; i >= 0; i--) {
    if (i + 3 <= m) {
      string tar = s.substr(i, 3);
      if (mp.find(tar) != mp.end()) {
        if (dp[i + 3] != -1) dp[i] = i + 3;
      }
    }
    if (i + 2 <= m) {
      string tar = s.substr(i, 2);
      if (mp.find(tar) != mp.end()) {
        if (dp[i + 2] != -1) dp[i] = i + 2;
      }
    }
  }

  if (dp[0] == -1) {
    cout << "-1\n";
    return;
  }
  ll act = 0;
  vector<tlll> ans;
  while (act < m) {
    if (dp[act] == act + 2) {
      ans.push_back(mp[s.substr(act, 2)]);
    }
    if (dp[act] == act + 3) {
      ans.push_back(mp[s.substr(act, 3)]);
    }
    act = dp[act];
  }
  cout << SZ(ans) << "\n";
  for (auto [l, r, id]: ans) {
    cout << l + 1 << " " << r + 1 << " " << id + 1 << endl;
  }
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

