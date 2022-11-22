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
  vector<int> s(n);
  for (int &x : s) cin >> x;
  int mx = *max_element(s.begin(), s.end());
  vector<int> tmp(s);
  nth_element(tmp.begin(), tmp.begin() + 1, tmp.end(), greater{});
  int second_mx = tmp[1];
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == mx) ans[i] = s[i] - second_mx;
    else ans[i] = s[i] - mx;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
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

