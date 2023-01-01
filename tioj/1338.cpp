#include <bits/stdc++.h>
#include "lib1338.h"

using namespace std;

const int mxn = 1e6 + 5, lgn = 21;

long long st[lgn][mxn], mn[lgn][mxn];

void init(int N, long long C[]) {
  for (int i = 0; i < N; i++) {
    st[0][i] = mn[0][i] = C[i];
  }
  for (int j = 1; j < lgn; j++) {
    for (int i = 0; i < N; i++) {
      st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
    }
  }
}

int query(int L, int R) {
  int k = __lg(R - L);
  return __gcd(st[k][L], st[k][R - (1 << k)]) == min(mn[k][L], mn[k][R - (1 << k)]);
}
