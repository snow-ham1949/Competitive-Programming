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
  string a, b;
  while (getline(cin, a)) {
    getline(cin, b);
    vector<int> cnta(26, 0), cntb(26, 0);
    for (char c : a) cnta[c - 'a']++;
    for (char c : b) cntb[c - 'a']++;
    for (int i = 0; i < 26; i++) {
      int minn = min(cnta[i], cntb[i]);
      for (int _ = 0; _ < minn; _++) cout << (char)(i + 97);
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

