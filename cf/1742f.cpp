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
  int q; cin >> q;
  ll d, k;
  string s;
  ll cnta = 0, cntb = 0;
  bool othera = 0, otherb = 0;
  while (q--) {
    cin >> d >> k >> s;  
    if (d == 1) {
      for (auto ch : s) {
        if (ch != 'a') othera = 1;
        else cnta += k;
      }
    }
    else {
      for (auto ch : s) {
        if (ch != 'a') otherb = 1;
        else cntb += k;
      }
    }

    if (otherb || (!othera && cnta < cntb)) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
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

