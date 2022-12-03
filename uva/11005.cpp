#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

void solve()
{
  vector<int> costs(36);
  for (int &x : costs) cin >> x;
  int q; scanf("%d", &q);
  while (q--) {
    int num; scanf("%d", &num);
    vector<int> ans;
    int mn = INT_MAX;
    for (int base = 2; base <= 36; base++) {
      int cost = 0;
      int x = num;
      while (x) {
        cost += costs[x % base];
        x /= base;
      }
      if (cost < mn) {
        ans.clear();
        mn = cost;
        ans.push_back(base);
      }
      else if (cost == mn) {
        ans.push_back(base);
      }
    }

    printf("Cheapest base(s) for number %d:", num);
    for (int x : ans) printf(" %d", x);
    printf("\n");
  }
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++)
  {
    if (i > 1) printf("\n");
    printf("Case %d:\n", i);
    solve(); 
  }
  return 0;
}

