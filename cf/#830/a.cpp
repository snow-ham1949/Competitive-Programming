#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int cost;
vector<int> a;
int n;
/*
void dfs(int id, int cos) {
  if (id == n + 1) return;
  int g;
  for (int i = 2; i <= n; i++) {
    g = __gcd(g, a[i]);
  }
  if (g == 1) {
    cost = min(cost, cos);
    return;
  }
  dfs(id + 1);
}
*/
void solve()
{
  cin >> n;
  a.resize(n + 5);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << "0\n";
    return;
  }
  cost = n;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  for (int i = n; i >= 2; i--) {
    int g1 = __gcd(a[i], i);
    int g2 = __gcd(a[i - 1], i - 1);
    if (__gcd(g1, g2) == 1) {
      cost = min(cost, n - i + 1 + n - (i - 1) + 1);
    }
    if (__gcd(g1, a[i - 1]) == 1) {
      cost = min(cost)
    }
  }
  cout << cost << endl;
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

