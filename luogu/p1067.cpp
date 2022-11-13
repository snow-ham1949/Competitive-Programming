#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

int n, num;

void solve()
{
  cin >> n;
  int flag = 1;
  for (int i = n; i >= 0; i--) {
    cin >> num;
    if (num == 0) continue;
    if (flag) {
      if (i == 0) printf("%d\n", num);
      else if (i == 1) {
        if (abs(num) == 1) {
          if (num == -1) printf("-x");
          else printf("x");
        }     
        else printf("%dx", num);
      }
      else {
        if (abs(num) == 1) {
          if (num == -1) printf("-x^%d", i);
          else printf("x^%d", i);
        }
        else printf("%dx^%d", num, i);       
      }
      flag = 0;
      continue;
    }
    if (num > 0) printf("+");
    if (i == 0) {
      printf("%d\n", num);
    }
    else if (i == 1) {
       if (abs(num) == 1) {
        if (num == -1) printf("-x");
        else printf("x");
      }     
      else printf("%dx", num);
    }
    else {
      if (abs(num) == 1) {
        if (num == -1) printf("-x^%d", i);
        else printf("x^%d", i);
      }
      else printf("%dx^%d", num, i);
    }
  }
  if (flag) printf("0\n");
}

int main() {
  //ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

