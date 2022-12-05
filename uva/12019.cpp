#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int day[13] = {0, 3, 7, 7, 4, 2, 6, 4, 1, 5, 3, 7, 5};
string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

void solve()
{
  int m, d; cin >> m >> d;
  if (d >= day[m]) {
    cout << days[(d - day[m]) % 7] << "\n";
  }
  else {
    int diff = day[m] - d;
    cout << days[7 - diff] << "\n";
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

