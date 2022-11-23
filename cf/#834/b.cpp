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
  int n, s; cin >> n >> s;
  vector<int> vis(1000 + 5, 0);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    vis[x] = 1;
    mx = max(mx, x);
  }
  int tot = 0;
  for (int i = 1; i <= mx; i++) if (!vis[i]) tot += i;
  if (tot > s) {
    cout << "No\n";
    return;
  }

  int cur = mx;
  while (tot < s) {
    while (vis[cur]) cur++;
    vis[cur] = 1;
    tot += cur;
  }
  tot > s ? cout << "No\n" : cout << "Yes\n";
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

