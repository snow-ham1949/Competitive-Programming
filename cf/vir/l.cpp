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
int c[3][mxn];
int p, pi; // smallest r such that cnt[pi - 'A'][r] == n
int n;

bool change1(char ch) {
  int x = (ch - 'A' + 1) % 3, y = (ch - 'A' + 2) % 3;
  for (int l = 1, r = 1; l <= 3 * n; l++) {
    if (r < l) r = l;
    while ((c[x][r] - c[x][l - 1] < c[x][3 * n] - n || 
           c[y][r] - c[y][l - 1] < c[y][3 * n] - n)
           && r <= 3 * n) r++;
    if (c[x][r] - c[x][l - 1] == c[x][3 * n] - n && 
        c[y][r] - c[y][l - 1] == c[y][3 * n] - n) {
          cout << "1\n" << l << " " << r << " " << ch << endl;
          return 1;
    }
  }
  return 0;
}

void change2() {
  cout << "2\n";
  int x = (pi - 'A' + 1) % 3, y = (pi - 'A' + 2) % 3;
  char X = x + 'A', Y = y + 'A';
  cout << p + 1 << " " << p + n - c[x][p] << " " << X << endl;
  cout << p + n - c[x][p] + 1 << " " << 3 * n << " " << Y << endl;
}

void solve()
{
  cin >> n;
  string s; cin >> s;
  s = "&" + s;
  for (int i = 1; i <= 3 * n; i++) {
    for (int j = 0; j < 3; j++) c[j][i] = c[j][i - 1];
    int id = s[i] - 'A';
    c[id][i] = c[id][i - 1] + 1;
    if (!p && c[id][i] == n) {
      p = i;
      pi = s[i];
    }
  }

  if (c[0][3 * n] == c[1][3 * n] && c[1][3 * n] == n) {
    cout << "0\n";
    return;
  }

  if (change1('A') || change1('B') || change1('C')) return;

  change2();
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

