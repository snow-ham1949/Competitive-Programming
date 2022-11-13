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
  vector<int> v;
  int sum = 0;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    v.emplace_back(x);
    sum += x;
  }
  int ans = n;
  for (int cut = 0; cut < n; cut++) {
    //fprintf(stderr, "goal cut: %d\n", cut);
    if (sum % (cut + 1) != 0) continue;
    int l = 0, r = 0, goal = sum / (cut + 1);
    int max_seg = -1, cur_sum = 0, cur_cut = 0;
    while (r < n) {
      if (cur_sum + v[r]== goal) {
        //fprintf(stderr, "    l: %d, r: %d, cur_cut: %d\n", l, r, cur_cut);
        max_seg = max(max_seg, r - l + 1);
        l = r + 1;
        r = l;
        cur_cut++;
        cur_sum = 0;
      } else {
        cur_sum += v[r];
        r++;
        //fprintf(stderr, "    l: %d, r: %d, cur_sum: %d\n", l, r, cur_sum);
      }
      if (cur_sum > goal) break;
    }
    //fprintf(stderr, "    final cut: %d\n", cur_cut);
    if (cur_sum == goal) {
      max_seg = max(max_seg, r - l);
      //fprintf(stderr, "into this if\n");
    }
    if (cur_cut == cut + 1) {
      //fprintf(stderr, "max seg: %d\n", max_seg);
      ans = min(ans, max_seg);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

