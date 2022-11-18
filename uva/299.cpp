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
  vector<int> v(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (v[i] > v[j]) {
        swap(v[i], v[j]);
        cnt++;
      }
    }
  }
  printf("Optimal train swapping takes %d swaps.\n", cnt);
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  scanf("%d", &t);
  while (t--)
  {
    solve(); 
  }
  return 0;
}

