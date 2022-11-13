#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int a[105];

void solve()
{
  set<int> s;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  set<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s.find(a[i] + a[j]) != s.end()) ans.insert(a[i] + a[j]);
    }
  }
  cout << SZ(ans) << endl;
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

