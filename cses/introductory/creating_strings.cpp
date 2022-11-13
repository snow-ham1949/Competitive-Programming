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
  string t; cin >> t;
  map<char, int> mp;
  for (auto ch : t) mp[ch]++;
  string s = "";
  for (auto it : mp) {
    string tmp(it.Y, it.X);
    s += tmp;
  }
  set<string> st;
  do {
    st.insert(s);
  } while (next_permutation(s.begin(), s.end()));
  cout << SZ(st) << endl;
  for (auto ss: st) cout << ss << endl;
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

