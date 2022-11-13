#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

int cal(const string &s, char c) {
  if (s.size() == 1) {
    return s[0] != c;
  }
  int mid = SZ(s) / 2;
  int cntl = mid - count(s.begin(), s.begin() + mid, c) +
             cal(string(s.begin() + mid, s.end()), c + 1);
  int cntr = mid - count(s.begin() + mid, s.end(), c) +
             cal(string(s.begin(), s.begin() + mid), c + 1);
  return min(cntl, cntr);
}

void solve()
{
  int n; cin >> n;
  string s; cin >> s;
  cout << cal(s, 'a') << endl;
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

