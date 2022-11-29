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
  int n, p; cin >> n >> p;
  vector<int> days(n + 5, 0);
  for (int i = 0, x; i < p; i++) {
    cin >> x;
    for (int j = x; j <= n; j += x) {
      days[j] = 1;
    }
  }
  for (int i = 6; i <= n; i += 7) {
    days[i] = days[i + 1] = 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += (days[i] == 1);
  }
  cout << cnt << "\n";
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

