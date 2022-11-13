#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve()
{
  int date1, date2, cnt = 0;
  cin >> date1 >> date2;
  for (int month = 1; month <= 12; month++) {
    for (int day = 1; day <= days[month]; day++) {
      int reverse_year = month * 100 + day;
      int tmp_year = reverse_year, year = 0;
      for (int i = 0; i < 4; i++) {
        year = year * 10 + tmp_year % 10;
        tmp_year /= 10;
      }
      year = year * 10000 + reverse_year;
      if (year >= date1 && year <= date2) cnt++;
    }
  }
  cout << cnt << endl;
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

