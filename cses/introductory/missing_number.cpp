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
  int n; cin >> n;
  vector<int> cnt(n + 5);
  for (int i = 0; i < n - 1; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      cout << i << endl;
      break;
    }
  }
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

