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
  int ans = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && s[i] == s[j]) j++;
    string color = "RGB";
    color.erase(color.find(s[i]), 1);
    if (j < n) color.erase(color.find(s[j]), 1);
    for (int k = i + 1; k < j; k += 2) {
      ans++;
      s[k] = color[0];
    }
    i = j;
  }
  cout << ans << endl << s << endl;
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

