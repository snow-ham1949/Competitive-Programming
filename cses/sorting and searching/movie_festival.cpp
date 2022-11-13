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
  int n; cin >> n;
  vector<pii> movies;
  for (int i = 0, s, t; i < n; i++) {
    cin >> s >> t;
    movies.push_back({t, s});
  }
  sort(movies.begin(), movies.end());
  int cur = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if (movies[i].Y >= cur) {
      cur = movies[i].X;
      ans++;
    }
  }
  cout << ans << endl;
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

