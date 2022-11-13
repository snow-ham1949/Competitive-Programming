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

void solve()
{
  int n; cin >> n;
  vector<pii> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());
  int round = 1;
  for (int i = 1; i < n; i++) {
    if (v[i].Y < v[i - 1].Y) round++; 
  }
  cout << round << endl;
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

