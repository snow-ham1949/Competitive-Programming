#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;

int b[mxn], p[mxn], vis[mxn];

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) vis[i] = p[i] = 0;
  for (int i = 1; i <= n / 2; i++) {
    cin >> b[i];
    vis[b[i]] = i;
    p[2 * i] = b[i];
  }

  set<int> st; // unused
  for (int i = n; i >= 1; i--) {
    if (!vis[i]) {
      if (st.empty()) {
        cout << "-1\n";
        return;
      }
      int x = *(--st.end());
      p[2 * x - 1] = i;
      st.erase(--st.end());
    }
    else {
      st.insert(vis[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << p[i] << " \n"[i == n];
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

