#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
int a[mxn], vis[mxn];

void solve()
{
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int cur = 0, mx = 0;
  for (int i = 0; i < min(30, n); i++) {
    int id = -1;
    for (int j = 0; j < n; j++) {
      if (vis[j]) continue;
      if ((cur | a[j]) > mx) {
        id = j;
        mx = cur | a[j];
      }
    }
    if (id == -1) break;
    vis[id] = 1;
    cur = mx;
    cout << a[id] << " ";
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) cout << a[i] << " ";
  }
  cout << endl;
  memset(a, 0, sizeof(a));
  memset(vis, 0, sizeof(vis));
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

