#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

struct MP {
  int a, b, g, k, id;
} mp[10000 + 5];
int x, y;

bool chk(int id) {
  return x >= mp[id].a && x <= mp[id].a + mp[id].g && y >= mp[id].b && y <= mp[id].b + mp[id].k;
}

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> mp[i].a >> mp[i].b >> mp[i].g >> mp[i].k;
    mp[i].id = i;
  }
  cin >> x >> y;
  for (int i = n; i >= 1; i--) {
    if (chk(i)) {
      cout << i << endl;
      return;
    }
  }
  cout << "-1\n";
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

