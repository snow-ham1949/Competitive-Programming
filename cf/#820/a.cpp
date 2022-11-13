#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (a < abs(b - c) + c) cout << "1\n";
  else if (a > abs(b - c) + c) cout << "2\n";
  else cout << "3\n";
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

