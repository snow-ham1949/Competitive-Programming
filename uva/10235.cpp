#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1e6 + 5;
int n;
bool not_prime[mxn];

void init() {
  not_prime[1] = 1;
  for (int i = 2; i < mxn; i++) {
    for (int j = 2 * i; j < mxn; j += i) not_prime[j] = 1;
  }
}

void solve()
{
  if (not_prime[n]) cout << n << " is not prime.\n";
  else {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    int _n = stoi(s);
    if (not_prime[_n] || n == _n) cout << n << " is prime.\n";
    else cout << n << " is emirp.\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  init();
  while (cin >> n)
  {
    solve(); 
  }
  return 0;
}

