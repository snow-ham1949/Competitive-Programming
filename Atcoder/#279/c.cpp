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
  int h, w; cin >> h >> w;
  char grid_s[h][w], grid_t[h][w];
  map<string, int> ms, mt;
  
  for (int i = 0; i < h; i++) {
    string s; cin >> s;
    for (int j = 0; j < w; j++) {
      grid_s[i][j] = s[j];
    }
  }

  for (int i = 0; i < h; i++) {
    string s; cin >> s;
    for (int j = 0; j < w; j++) {
      grid_t[i][j] = s[j];
    }
  }

  for (int i = 0; i < w; i++) {
    string s = "";
    for (int j = 0; j < h; j++) {
      s += grid_s[j][i];
    }
    ms[s]++;
  }

  for (int i = 0; i < w; i++) {
    string s = "";
    for (int j = 0; j < h; j++) {
      s += grid_t[j][i];
    }
    mt[s]++;
  }


  if (ms == mt) cout << "Yes\n";
  else cout << "No\n";
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

