#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

char a[8][8];
int ans;
int vis[8][8];

bool check(int x, int y) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (vis[i][j]) {
        if (abs(i - x) == abs(j - y)) return false;
        if (i == x || j == y) return false;
      }
    }
  }
  return true;
}

void dfs(int num) {
  if (num == 8) {
    ans++;
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (a[i][num] == '.' && check(i, num)) {
      vis[i][num] = 1;
      dfs(num + 1);
      vis[i][num] = 0;
    }
  }
}

void solve()
{
  for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) cin >> a[i][j];
  dfs(0);
  cout << ans;
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

