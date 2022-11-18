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
  vector<vector<char>> output(100, vector<char>(100, ' '));
  string s;
  int max_sz = 0;
  while (getline(cin, s) && s != "") {
    v.push_back(s);
    max_sz = max(max_sz, SZ(s));
  }
  
  int n = SZ(v);
  for (int i = 0; i < n; i++) {
    for (int j = 0 ; j < SZ(v[i]); j++) {
      output[j][n - i - 1] = v[i][j];
    }
  }

  for (int i = 0; i < max_sz; i++) {
    for (int j = 0; j < n; j++) {
      cout << output[i][j];
    }
    cout << endl;
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

