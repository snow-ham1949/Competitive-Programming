#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

map<char, vector<int>> mp;

void init() {
  mp['c'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
  mp['d'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
  mp['e'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
  mp['f'] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
  mp['g'] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
  mp['a'] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
  mp['b'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  mp['C'] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
  mp['D'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
  mp['E'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
  mp['F'] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
  mp['G'] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
  mp['A'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
  mp['B'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
}

void solve()
{
  string s; getline(cin, s);
  vector<int> cnt(11, 0), status(11, 0);
  for (int i = 0; s[i]; i++) {
    for (int j = 1; j <= 10; j++) {
      if (mp[s[i]][j]) {
        if (status[j]) continue;
        else {
          status[j] = 1;
          cnt[j]++;
        }
      }
      else {
        status[j] = 0;
      }
    }
  }
  for (int i = 1; i <= 10; i++) {
    cout << cnt[i] << " \n"[i == 10];
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  init();
  int t = 1;
  cin >> t;
  string s;
  getline(cin, s);
  while (t--)
  {
    solve(); 
  }
  return 0;
}

