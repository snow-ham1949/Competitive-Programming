#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

void solve()
{
  set<ll> st;
  ll ans;
  st.insert(1);
  for (int i = 0; i < 1500; i++) {
    ans = *st.begin();
    st.erase(ans);
    st.insert(ans * 2);
    st.insert(ans * 3);
    st.insert(ans * 5);
  }
  cout << "The 1500'th ugly number is " << ans << ".\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

