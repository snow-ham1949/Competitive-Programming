#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;
const int logn = 19;

int st[mxn][logn]; // sparse table, store answer for [i, i + 2^j - 1]
int a[mxn]; // array
int lg[mxn]; // log value
int n, q;

void init()
{
  lg[1] = 0;
  for (int i = 2; i < mxn; i++) lg[i] = lg[i / 2] + 1;
  for (int i = 0; i < n; i++) cin >> st[i][0];
  for (int j = 1; j < logn; j++)
  {
    for (int i = 0; i + (1 << j) <= n; i++)
    {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}

void solve()
{
  cin >> n >> q;
  init();

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int j = lg[r - l + 1];
    cout << min(st[l][j], st[r - (1 << j) + 1][j]) << endl;
  }
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

