#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second
const int mxn = 1e4 + 5;
string a[mxn], b[mxn];
ll n, m, cnt;

void solve()
{
  string s;
  while (getline(cin, s) && s != "EOF") {
    n++;
    for (char c : s) {
      if (c == '<') {
        if (!a[n].empty()) a[n].pop_back();
      }
      else a[n].push_back(c);
    }
  }
  while (getline(cin, s) && s != "EOF") {
    if (++m > n) break;
    for (char c : s) {
      if (c == '<') {
        if (!b[m].empty()) b[m].pop_back();
      }
      else b[m].push_back(c);
    }
    for (int i = 0; i < min(SZ(a[m]), SZ(b[m])); i++) cnt += a[m][i] == b[m][i];
  }
  int se; cin >> se;
  cout << (ll)(cnt * 60 / se + 0.5) << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

