#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int n;

int convert(int x, int y) {
  return x * n + y;
}

void solve()
{
  int player = 0, winner = -1, round = -1;
  set<string> st; // finding duplicate
  string g(n * n, '0');
  string g90(g), g180(g), g270(g);

  int x, y;
  char move;
  for (int t = 0; t < 2 * n; t++) {
    scanf("%d %d %c", &x, &y, &move);
    if (winner != -1) continue;
    x--, y--;
    int pos = convert(x, y);
    if (move == '+') g[pos] = '1';
    else g[pos] = '0';
    
    if (st.find(g) != st.end()) {
      winner = player ^ 1;
      round = t + 1;
    }
    else {
      g90[convert(n - 1 - y, x)] = g180[n * n - 1 - pos] = g270[convert(y, n - 1 - x)] = g[pos];
      st.insert(g90);
      st.insert(g180);
      st.insert(g270);
      st.insert(g);
    }

    player ^= 1;
  }
  if (winner == -1) {
    puts("Draw");
  }
  else {
    printf("Player %d wins on move %d\n", winner + 1, round);
  }
}

int main() {
  // ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (scanf("%d", &n) && n)
  {
    solve(); 
  }
  return 0;
}

