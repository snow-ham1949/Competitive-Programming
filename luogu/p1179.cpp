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
  int L, R, cnt = 0;
  cin >> L >> R;
  for (int i = L; i <= R; i++) {
    string s = to_string(i);
    for (int j = 0; j < SZ(s); j++) {
      if (s[j] == '2') cnt++;
    }
  }
  cout << cnt << endl;
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

