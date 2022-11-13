#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int a[10005];

void solve()
{
  int l, m; cin >> l >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    for (int j = u; j <= v; j++) a[j] = -1;
  }
  int cnt = 0;
  for (int i = 0; i <= l; i++) {
    cnt += (a[i] != -1);
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

