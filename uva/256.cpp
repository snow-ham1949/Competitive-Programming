#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

vector<string> ans2 = {"00", "01", "81"};
vector<string> ans4 = {"0000", "0001", "2025", "3025", "9801"};
vector<string> ans6 = {"000000", "000001", "088209", "494209", "998001"};
vector<string> ans8 = {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"};

void solve()
{
  int n;
  while (cin >> n) {
    if (n == 2) {
      for (auto s : ans2) cout << s << "\n";
    }
    else if (n == 4) {
      for (auto s : ans4) cout << s << "\n";
    }
    else if (n == 6) {
      for (auto s : ans6) cout << s << "\n";
    }
    else {
      for (auto s : ans8) cout << s << "\n";
    }
  }
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

