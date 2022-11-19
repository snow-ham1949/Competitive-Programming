#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second
#define ALL(v) (v).begin(), (v).end()

vector<string> S;
set<string> st;

void gen(int id, int left, string ans){
  if (left < 0) return;

  if (id == SZ(S)) {
    if (SZ(ans) >= 3 && st.find(ans) == st.end()) {
      cout << ans << endl;
      exit(0);
    }
    return;
  }
  
  if (SZ(ans) > 0 && ans.back() != '_') {
    gen(id, left, ans + "_");
  }
  else {
    gen(id + 1, left, ans + S[id]);
    if (SZ(ans) > 0) gen(id, left - 1, ans + "_");
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  S.resize(n);
  for (string &str: S) cin >> str;
  sort(ALL(S));
  for (int i = 0; i < m; i++) {
    string s; cin >> s;
    st.insert(s);
  }

  int left = 16 - (n - 1);
  for (string s : S) left -= SZ(s);
  
  do {
    gen(0, left, "");
  } while (next_permutation(ALL(S)));
  
  cout << "-1\n";
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

