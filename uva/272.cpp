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
  vector<string> v;
  string s;
  while (getline(cin, s)) {
    v.push_back(s);
  }
  int cnt = 0, n = SZ(v);
  for (int i = 0; i < n; i++) {
    for (int j = 0; v[i][j]; j++) {
      if (v[i][j] == '"') {
        if (cnt & 1) {
          v[i].erase(j, 1);
          v[i].insert(j, "''");
        }
        else {
          v[i].erase(j, 1);
          v[i].insert(j, "``");
        }
        cnt ^= 1;
      }
    }
  }
  for (string str : v) cout << str << endl; 
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

