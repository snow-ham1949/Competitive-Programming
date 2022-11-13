#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

vector<ll> v;
ll ans = LLONG_MAX, tot = 0;
int n;

void dfs(int id, ll sum) {
  if (id == n) {
    ll others = tot - sum;
    ans = min(ans, abs(others - sum));
    return;
  }
  dfs(id + 1, sum + v[id]);
  dfs(id + 1, sum);
}

void solve()
{
  cin >> n;
  ll x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    tot += x;
    v.push_back(x);
  }
  dfs(0, 0ll);
  cout << ans << endl;
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

