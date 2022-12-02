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
  int cd, cm, cy, bd, bm, by;
  scanf("%d/%d/%d", &cd, &cm, &cy);
  scanf("%d/%d/%d", &bd, &bm, &by);
  int age = cy - by;
  if (bm > cm || (bm == cm && bd > cd)) age--;
  if (age < 0) printf("Invalid birth date\n");
  else if (age > 130) printf("Check birth date\n");
  else printf("%d\n", age);
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++)
  {
    printf("Case #%d: ", i);
    solve(); 
  }
  return 0;
}

