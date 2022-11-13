#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
  string s; cin >> s;
  string a = "", b = "";
  int l = 0, r = s.length() - 1;
  int round = 0;
  while (l <= r)
  {
    if (round == 0) {
      // Alice
      if (s[l] < s[r]) {
        a = s[l] + a;
        l++;
      } else {
        a = s[r] + a;
        r--;
      }
    } else {
      if (s[l] < s[r]) {
        b = s[l] + b;
        l++;
      } else {
        b = s[r] + b;
        r--;
      }
    }
    //cerr << a << endl;
    //cerr << b << endl;
    round ^= 1;
    //fprintf(stderr, "l: %d, r: %d\n", l, r);
  }
  if (a < b) cout << "Alice\n";
  else if (a > b) cout << "Bob\n";
  else cout << "Draw\n";
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

