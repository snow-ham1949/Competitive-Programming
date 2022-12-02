#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

map<char, ll> mp;

void init() {
  int tp = 0;
  for (char c = '0'; c <= '9'; c++) {
    mp[c] = tp++;
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    mp[c] = tp++;
  }
  for (char c = 'a'; c <= 'z'; c++) {
    mp[c] = tp++;
  }
}

void solve()
{
  string s;
  while (cin >> s) {
    ll sum = 0;
    int id = 0, n = SZ(s);
    ll base = 1;
    while (!isalnum(s[id])) id++;
    for (int i = id; i < n; i++) {
      sum += mp[s[i]];
      base = max(base, mp[s[i]]);
    }
    for (; base < 62; base++) {
      if (sum % base == 0) {
        cout << base + 1 << "\n";
        break;
      }
    }
    if (base == 62) cout << "such number is impossible!\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  init();
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

