#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
int a[mxn];

vector<int> pairs[1000 + 5];

void init() {
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      if (__gcd(i, j) == 1) {
        pairs[i].push_back(j);
      }
    }
  }
}

void solve()
{
  int n; cin >> n;
  vector<int> id[1000 + 5];
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    id[x].push_back(i);
  }
  int mx = -1;
  for (int i = 1; i <= 1000; i++) {
    for (int j : pairs[i]) {
      if (!id[i].empty() && !id[j].empty()) {
        mx = max(mx, id[i].back() + id[j].back());
      }
    }
  }
  cout << mx << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  init();
  while (t--)
  {
    solve(); 
  }
  return 0;
}

