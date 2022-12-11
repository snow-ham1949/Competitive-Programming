#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

double cost[5][3] = {
  {0.10, 0.06, 0.02},
  {0.25, 0.15, 0.05},
  {0.53, 0.33, 0.13},
  {0.87, 0.47, 0.17},
  {1.44, 0.80, 0.30}};

void solve()
{
  char step[2], name[10];
  int sh, sm, eh, em; // start hour, start minute, end hour, end minute
  while (~scanf("%s", step) && step[0] != '#') {
    scanf("%s%d%d%d%d", name, &sh, &sm, &eh, &em);
    getchar();
    int day = 0, evening = 0, night = 0;
    vector<int> used(1440 + 5, 0);
    int stot = sh * 60 + sm, etot = eh * 60 + em;
    if (etot <= stot) {
      for (int i = 0; i < etot; i++) {
        used[i] = 1;
      }
      for (int i = stot; i < 1440; i++) {
        used[i] = 1;
      }
    }
    else {
      for (int i = stot; i < etot; i++) {
        used[i] = 1;
      }
    }
    for (int i = 0; i < 480; i++) night += used[i];
    for (int i = 480; i < 1080; i++) day += used[i];
    for (int i = 1080; i < 1320; i++) evening += used[i];
    for (int i = 1320; i < 1440; i++) night += used[i];
    int id = step[0] - 'A';
    double price = day * cost[id][0] + evening * cost[id][1] + night  * cost[id][2];
    printf("%10s%6d%6d%6d%3s%8.2lf\n", name, day, evening, night, step, price);
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

