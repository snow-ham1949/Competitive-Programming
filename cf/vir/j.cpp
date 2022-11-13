#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

#define eb emplace_back
stack<int> stk[2]; // for A, B
vector<pii> ans;

void solve()
{
  int n; cin >> n;
  string s; cin >> s;
  int cnta = 0, cntbc = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == 'A') cnta++;
  }
  cntbc = n - cnta;
  if (cntbc < 0) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (s[i - 1] == 'A') stk[0].push(i);
    else if (s[i - 1] == 'B') {
      if (cntbc) {
        stk[1].push(i);
        cntbc--;
      }
      else {
        if (stk[0].empty()) {
          cout << "NO\n";
          return;
        }
        ans.eb(stk[0].top(), i);
        stk[0].pop();
      }
    } 
    else {
      if (stk[0].empty() && stk[1].empty()) {
        cout << "NO\n";
        return;
      }
      else if (stk[1].size()) {
        ans.eb(stk[1].top(), i);
        stk[1].pop();
      } 
      else {
        ans.eb(stk[0].top(), i);
        stk[0].pop();
      }
    }
  }
  cout << "YES\n";
  for (auto p : ans) cout << p.X << " " << p.Y << endl;
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

