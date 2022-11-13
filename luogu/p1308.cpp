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
  string pat, txt;
  getline(cin, pat);
  getline(cin, txt);
  for (int i = 0; i < SZ(pat); i++) pat[i] = tolower(pat[i]);
  for (int i = 0; i < SZ(txt); i++) txt[i] = tolower(txt[i]);
  pat = ' ' + pat + ' ';
  txt = ' ' + txt + ' ';
  if (txt.find(pat) == string::npos) cout << "-1\n";
  else {
    int first = txt.find(pat);
    int ptr = txt.find(pat), cnt = 0;
    while (ptr != string::npos) {
      ++cnt;
      ptr = txt.find(pat, ptr + 1);
    }
    cout << cnt << " " << first << endl;
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

