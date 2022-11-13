#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int bs(int x, int y, vector<vector<int>>& v){
  return upper_bound(v[x].begin(), v[x].end(), y) - v[x].begin();
}

void solve()
{
  deque<int> dq;
  int n, q; cin >> n >> q;
  vector<int> a(n + 5);
  vector<vector<int>> win(n + 5, vector<int>());
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) dq.push_back(i);
  
  int winner = 1;
  for (int rd = 1; rd <= n; rd++) { // rd : round
    if (a[winner] > a[dq.front()]) {
      win[winner].push_back(rd);
      int x = dq.front();
      dq.pop_front();
      dq.push_back(x);
    }
    else {
      win[dq.front()].push_back(rd);
      dq.push_back(winner);
      winner = dq.front();
      dq.pop_front();
    }
  }

  int x, y;
  while (q--) {
    cin >> x >> y;
    if (y <= n) {
      cout << bs(x, y, win) << endl;
    }
    else {
      cout << bs(x, y, win) + (a[x] == n ? y - n : 0) << endl;
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

