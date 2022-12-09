#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

string s, t;

void solve()
{
  vector<int> cnts(26, 0), cntt(26, 0);
  for (char c : s) cnts[c - 'A']++;
  for (char c : t) cntt[c - 'A']++;
  sort(cnts.begin(), cnts.end());
  sort(cntt.begin(), cntt.end());
  if (cnts == cntt) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (cin >> s >> t)
  {
    solve(); 
  }
  return 0;
}

