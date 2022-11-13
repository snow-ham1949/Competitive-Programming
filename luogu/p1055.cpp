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
  string s; cin >> s;
  string mod="0123456789X";
  int cnt = 1, n = SZ(s), sum = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != '-') {
      sum += (s[i] - '0') * cnt;
      cnt++;
    }
  }
  if (mod[sum % 11] == s[n - 1]) cout << "Right\n";
  else {
    s[n - 1] = mod[sum % 11];
    cout << s << endl;
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

