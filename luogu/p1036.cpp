#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int a[20 + 5];
int n, k, ans = 0;

bool isprime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

void dfs(int id, int pick, int sum) {
  if (pick == k) {
    if (isprime(sum)) ans++;
    return;
  }
  if (id == n) return;
  dfs(id + 1, pick + 1, sum + a[id]);
  dfs(id + 1, pick, sum);
}

void solve()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(0, 0, 0);
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

