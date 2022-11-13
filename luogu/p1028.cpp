#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int a[1000 + 5];

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      a[i] += a[j];
    }
    a[i]++;
  }
  cout << a[n] << endl;
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

