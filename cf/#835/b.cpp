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
  int n; cin >> n;
  string s; cin >> s;
  vector<int> cnt(26 + 5, 0);
  for (char c : s) {
    cnt[c - 'a'] = 1;
  }
  int ans = -1;
  for (int i = 0; i <= 26; i++) {
    if (cnt[i] == 1) ans = i;
  }
  cout << ans + 1<< endl;
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

