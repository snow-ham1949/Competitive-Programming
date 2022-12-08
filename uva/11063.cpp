#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int n;

void solve()
{
  vector<int> a(n);
  for (int &x : a) cin >> x;
  if (a[0] < 1) {
    cout << ": It is not a B2-Sequence.\n\n";
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) {
      cout << ": It is not a B2-Sequence.\n\n";
      return;
    }
  }
  set<int> st;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (st.count(a[i] + a[j])) {
        cout << ": It is not a B2-Sequence.\n\n";
        return;
      }
      st.insert(a[i] + a[j]);
    }
  }
  cout << ": It is a B2-Sequence.\n\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (cin >> n)
  {
    cout << "Case #" << T++;
    solve(); 
  }
  return 0;
}

