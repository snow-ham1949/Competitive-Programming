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
  vector<int> a(n + 5);
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (a[n - 1] > a[n]) {
    cout << "-1\n";
    return;
  }
  if (a[n] >= 0) {
    cout << n - 2 << endl;
    for (int i = 1; i <= n - 2; i++) {
      cout << i << " " << n - 1 <<  " " << n << endl;
    }
  }
  else {
    int flag = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i] < a[i - 1]) {
        flag = 0; break;
      }
    }
    if (flag) cout << "0\n";
    else cout << "-1\n";
  }
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

