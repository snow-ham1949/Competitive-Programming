#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

string keyboard = " 1234567890-=wertyuiop[]\\sdfghjkl;'xcvbnm,./";
string decode = " `1234567890-qwertyuiop[]asdfghjkl;zxcvbnm,.";

void solve()
{
  vector<string> v;
  string s;
  while (getline(cin, s)) {
    v.push_back(s);
  }
  
  for (string ss : v) {
    for (int i = 0; ss[i]; i++) {
      for (int j = 0; decode[j]; j++) {
        ss[i] = tolower(ss[i]);
        if (ss[i] == keyboard[j]) {
          char ch = toupper(decode[j]);
          cout << ch;
        }
      }
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

