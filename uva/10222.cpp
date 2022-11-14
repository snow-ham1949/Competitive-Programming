#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

string keyboard = " 234567890-=ertyuiop[]\\dfghjkl;'cvbnm,./";
string decode = " `1234567890qwertyuiop[asdfghjklzxcvbnm,";

void solve()
{
  string s; getline(cin, s);
  for (int i = 0; s[i]; i++) s[i] = tolower(s[i]);
  for (int i = 0; s[i]; i++) {
    for (int j = 0; decode[j]; j++) {
      if (s[i] == keyboard[j]) {
        cout << decode[j];
      }
    }
  }
  cout << endl;
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

