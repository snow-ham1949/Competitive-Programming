#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

double r, s, a, arc, chrod;
string unit;
#define PI acos(0.0)*2.0

void solve()
{
  if (unit == "min") a /= 60.0;
  if (a > 180.0) a = 360.0 - a;
  arc = 2.0 * PI * (r + s) * a / 360.0;
  chrod = 2 * (r + s) * cos((90.0 - a / 2.0) / 180.0 * PI);
  cout << fixed << setprecision(6) << arc << " " << chrod << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  r = 6440.0;
  while (cin >> s >> a >> unit)
  {
    solve(); 
  }
  return 0;
}

