#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

struct pt{
  int x, y, id;
  bool operator < (pt b) {
    if (x == b.x) return y < b.y;
    return x < b.x;
  }
  bool operator > (pt b) {
    if (x == b.x) return y > b.y;
    return x > b.x;
  }
  bool operator == (pt b) {
    return x == b.x && y == b.y;
  }
  pt operator+(pt b) {return {x + b.x, y + b.y}; }
  pt operator-(pt b) {return {x - b.x, y - b.y}; }
  int operator^(pt b) {return x * b.y - y * b.x;}
  int operator*(pt b) {return x * b.x + y * b.y;}
  int dis() {return x * x + y * y;}
}

bool cmp(pt a, pt b) {
  if (a == b) return a.id < b.id;
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

vector<pt> p, hull;
int n;

// build convex hull
void convex_hull() {
  sort(p.begin(), p.end(), cmp);

}

void solve()
{
  while (cin >> n) {
    if (n == 0) return;
    p.resize(n, {0, 0});
    for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y;
      p[i].id = i;
    }
    convex_hull();
  }
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

