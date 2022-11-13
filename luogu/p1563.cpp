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
  int n, m; cin >> n >> m;
  vector<pair<int, string>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].X >> v[i].Y;
  }
  int ptr = 0, a, s;
  for (int i = 0; i < m; i++) {
    cin >> a >> s;
    if (a == 0) {
      if (v[ptr].X == 0) ptr = (ptr - s + n) % n;
      else ptr = (ptr + s) % n;
    }
    else {
      if (v[ptr].X == 0) ptr = (ptr + s) % n;
      else ptr = (ptr - s + n) % n;
    }
  }
  cout << v[ptr].Y << endl;
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

