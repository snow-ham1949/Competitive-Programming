#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int a[100 + 5], b[100 + 5];

void f(int aa, int bb, int &sa, int &sb){
  if (aa == bb) return;
  // a wins
  if ((aa == 0 && (bb == 2 || bb == 3)) || (aa == 1 && bb == 3) || (aa == 2 && bb == 4) || (aa == 3 && bb == 4)) sa += 1;
  if ((aa == 1 && bb == 0) || (aa == 2 && bb == 1) || (aa == 3 && bb == 2) || (aa == 4 && (bb == 0 || bb == 1))) sa += 1;

  // b wins
  if ((aa == 0 && (bb == 1 || bb == 4)) || (aa == 1 && (bb == 2 || bb == 4)) || (aa == 2 && bb == 3)) sb += 1;
  if ((aa == 2 && bb == 0) || (aa == 3 && (bb == 0 || bb == 1)) || (aa == 4 && (bb == 2 || bb == 3))) sb += 1;

}

void solve()
{
  int n, na, nb; cin >> n >> na >> nb;
  for (int i = 0; i < na; i++) cin >> a[i];
  for (int i = 0; i < nb; i++) cin >> b[i];
  int scorea = 0, scoreb = 0;
  for (int i = 0; i < n; i++) {
    f(a[i % na], b[i % nb], scorea, scoreb);
  }
  cout << scorea << ' ' << scoreb << "\n";
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

