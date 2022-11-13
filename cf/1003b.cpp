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
  int a, b, x; cin >> a >> b >> x;
  string s = "";
  int cnt = x / 2;
  if (a > b) {
    for (int i = 0; i < cnt; i++) s += "01";
    if (x & 1) {
      s.append(a - cnt, '0');
      s.append(b - cnt, '1');
    }
    else {
      s.append(b - cnt, '1');
      s.append(a - cnt, '0');
    }
  }
  else {
    for (int i = 0; i < cnt; i++) s += "10";
    if (x & 1) {
      s.append(b - cnt, '1');
      s.append(a - cnt, '0');
    }
    else {
      s.append(a - cnt, '0');
      s.append(b - cnt, '1');
    }
  }
  cout << s << endl;
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

