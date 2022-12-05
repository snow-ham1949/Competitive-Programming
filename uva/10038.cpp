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
  vector<int> v(n);
  for (int &x : v) cin >> x;
  vector<int> cnt(n, 0);
  for (int i = 0; i < n - 1; i++) {
    if (abs(v[i + 1] - v[i]) < n)
      cnt[abs(v[i + 1] - v[i])]++;
  }
  for (int i = 1; i < n; i++) {
    if (cnt[i] == 0) {
      cout << "Not jolly\n";
      return;
    }
  }
  cout << "Jolly\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  //int t = 1;
  //cin >> t;
  while (cin >> n)
  {
    solve(); 
  }
  return 0;
}

