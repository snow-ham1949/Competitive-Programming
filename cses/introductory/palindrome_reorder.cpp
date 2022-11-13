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
  int n = SZ(s);
  map<char, int> mp;
  for (auto ch : s) mp[ch]++;
  char oddchar;
  int oddcnt = 0;
  for (auto it : mp) {
    if (it.Y & 1) {
      oddcnt++;
      oddchar = it.X;
    }
  }
  if (oddcnt > 1 || (n % 2 == 0 && oddcnt == 1)) {
    cout << "NO SOLUTION\n";
    return;
  }
  string first = "", second = "";
  for (auto it : mp) {
    string ss(it.Y / 2, it.X);
    first = first + ss;
    second = ss + second;
  }
  if (n & 1) {
    cout << first << oddchar << second << endl;
  } else {
    cout << first << second << endl;
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

