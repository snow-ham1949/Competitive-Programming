#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
  int n; cin >> n;
  if (n % 3 == 1) {
    for (int i = 1; i < n - 3; i++) cout << i << " ";
    cout << n - 2 << " " << n - 3 << " " << n - 1 << " " << n << endl;
  }
  else if (n % 3 == 2) {
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
  }
  else {
    if (n == 6) cout << "1 2 4 3 5 6\n";
    else {
      for (int i = 1; i < n - 5; i++) cout << i << " ";
      cout << n - 4 << " " << n - 5 << " ";
      cout << n - 2 << " " << n - 3 << " ";
      cout << n - 1 << " " << n << endl;
    }
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

