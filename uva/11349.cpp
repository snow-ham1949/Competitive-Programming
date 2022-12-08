#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

char str[3];

void solve()
{
  int n;
  scanf(" N = %d", &n);
  vector<ll> m(n * n);
  for (int i = 0; i < n * n; i++) {
    scanf("%lld", &(m[i]));
  }
  for (int i = 0; i < n * n; i++) {
    if (m[i] < 0) {
      printf("Non-symmetric.\n");
      return;
    }
  }
  for (int i = 0; i < n * n / 2; i++) {
    if (m[i] != m[n * n - i - 1]) {
      printf("Non-symmetric.\n");
      return;
    }
  }
  printf("Symmetric.\n");
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  fflush(stdin);
  for (int i = 1; i <= T; i++)
  {
    printf("Test #%d: ", i);
    solve(); 
  }
  return 0;
}

