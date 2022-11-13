#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

const int mxn = 100 + 5;
vector<int> a, d;

void build(int l, int r, int curD = 0) {
  if (r <= l) return;
  if (l == r - 1) {
    d[l] = curD;
    return;
  }
  int m = l;
  for (int i = l + 1; i < r; i++) {
    if (a[m] < a[i]) {
      m = i;
    }
  }
  d[m] = curD;
  build(l, m, curD + 1);
  build(m + 1, r, curD + 1);
}

void solve()
{
  int n; cin >> n;
  a.resize(n);
  for (auto &i : a) cin >> i;
  d.resize(n);
  build(0, n);
  for (int i = 0; i < n; i++) cout << d[i] << " ";
  cout << endl;
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

