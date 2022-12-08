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
  int s, d;
  cin >> s >> d;
  int win = s + d, lose = s - d;
  if (win < 0 || lose < 0 || win & 1 || lose & 1) {
    cout << "impossible\n";
  }
  else cout << win / 2 << " " << lose / 2 << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    solve(); 
  }
  return 0;
}

