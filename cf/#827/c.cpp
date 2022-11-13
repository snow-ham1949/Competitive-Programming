#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

void solve()
{
  string s;
  vector<string> v;
  for (int i = 0; i < 8; i++) {
    cin >> s;
    v.push_back(s);
  }

  for (int i = 0; i < 8; i++) {
    int flag = 1;
    for (int j = 0; j < 8; j++) {
      if (v[i][j] != 'R') {
        flag = 0;
        break;
      }
    }
    if (flag) {
      //fprintf(stderr, "Case #1: i: %d\n", i);
      cout << "R\n"; 
      return;
    }
  }

  for (int j = 0; j < 8; j++) {
    int flag = 1;
    for (int i = 0; i < 8; i++) {
      if (v[i][j] != 'B') {
        flag = 0;
        break;
      }
    }
    if (flag) {
      //fprintf(stderr, "Case #2: j: %d\n", j);
      cout << "B\n";
      return;
    }
  }
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

