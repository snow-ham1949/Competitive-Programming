#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int cnt[4500];

void init() {
  cnt[0] = 0, cnt[1] = 1;
  for (int i = 2; i < 4500; i++) {
    cnt[i] = cnt[i - 1] + i;
  }
}

void solve()
{
  int n;
  init();
  while (~scanf("%d", &n)) {
    int _n = 0;
    while (n > cnt[_n]) _n++;
    if (_n & 1) printf("TERM %d IS %d/%d\n", n, cnt[_n] - n + 1, n - cnt[_n - 1]);
    else printf("TERM %d IS %d/%d\n", n, n - cnt[_n - 1], cnt[_n] - n + 1);
  }
}

int main() {
  // ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

