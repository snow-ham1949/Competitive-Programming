#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

void hanoi(int a, int b, int c, int n) {
  if (n == 0) return;
  hanoi(a, c, b, n - 1);
  cout << a << " " << c << endl;
  hanoi(b, a, c, n - 1);
}

void solve()
{
  int n; cin >> n;
  cout << (1 << n) - 1 << endl;
  hanoi(1, 2, 3, n);
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

