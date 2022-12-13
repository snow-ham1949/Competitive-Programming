#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 1000;

vector<string> mp;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool chk(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
  char ch = mp[x][y];
  mp[x][y] = '.';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (chk(nx, ny) && mp[nx][ny] == ch) {
      dfs(nx, ny);
    }
  }
}

bool cmp(pii a, pii b) {
  return a.X == b.X ? a.Y < b.Y : a.X > b.X;
}

void solve()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    mp.push_back(s);
  }
  m = SZ(mp[0];)
  vector<int> type(26 + 5, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] >= 'a' && mp[i][j] <= 'z') {
        char ch = mp[i][j];
        dfs(i, j);
        type[ch - 'a']++;
      }
    }
  }

  vector<pii> v;
  for (int i = 0; i < 26; i++) {
    if (type[i]) v.push_back({type[i], i});
  }
  sort(v.begin(), v.end(), cmp);
  int sz = SZ(v);
  for (int i = 0; i < sz; i++) {
    char ch = 'a' + v[i].Y;
    cout << ch << ": " << v[i].X << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    cout << "World #" << i << "\n";
    solve(); 
  }
  return 0;
}

