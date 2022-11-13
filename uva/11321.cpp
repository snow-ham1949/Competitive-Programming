#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int n, m;
bool cmp(int a, int b) {
  if (a % m == b % m) {
    if ((a & 1) && !(b & 1)) return 1;
    else if (!(a & 1) && (b & 1)) return 0;
    else if ((a & 1) && (b & 1)) return a > b;
    else return a < b;
  }
  else {
    return a % m < b % m;
  }
}

void solve()
{
  while(cin >> n >> m && (n || m)) {
    vector<int> v(n);
    for (int &x: v) cin >> x;
    sort(v.begin(), v.end(), cmp);
    cout << n << " " << m << endl;
    for (int x : v) cout << x << endl;
  }
  cout << "0 0\n";
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

