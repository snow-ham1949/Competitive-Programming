#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 4e5 + 5;
int n;
vector<int> s; // salaries;

#define ALL(v) (v).begin(), (v).end()

struct BIT {
  ll bit[mxn];
  int lowbit(int x) {
    return x & (-x);
  }

  void update(int pos, ll val) {
    for (int i = pos; i <= mxn; i += lowbit(i)) bit[i] += val;
  }

  ll sum(int x) {
    ll res = 0;
    for (; x; x -= lowbit(x)) res += bit[x];
    return res;
  }

} bit;

void add(int x, int val) {
  int id = upper_bound(ALL(s), x) - s.begin();
  bit.update(id, val);
}

ll query(int x) {
  int id = upper_bound(ALL(s), x) - s.begin();
  return bit.sum(id);
}

void solve()
{
  int q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  s = a;

  vector<tuple<char, int, int>> ops;
  for (int i = 0; i < q; i++) {
    char ch;
    int x, y;
    cin >> ch >> x >> y;
    ops.push_back({ch, x, y});
    if (ch == '!') s.push_back(y);
  }

  sort(ALL(s));

  s.erase(unique(ALL(s)), s.end());

  for (int i : a) add(i, 1);

  for (auto [ch, x, y]: ops) {
    x--;
    if (ch == '!') {
      add(a[x], -1);
      a[x] = y;
      add(a[x], 1);
    } else {
      cout << query(y) - query(x) << endl;
    }
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

