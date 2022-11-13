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
  if (n & 1) {
    if (n == 3) cout << "-1\n";
    else {
      if (n == 5) cout << "3 4 5 1 2\n";
      else {
        for (int i = 1; i <= n - 6; i += 2) {
          cout << i + 1 << " " << i << " ";
        }
        cout << n - 2 << " " << n - 1 << " " << n << " " << n - 4 << " " << n - 3 << endl;
      }
    }
  } else {
    for (int i = 1; i <= n - 1; i += 2) cout << i + 1 << " " << i << " ";
    cout << endl;
  }
  return;
  //for (int num = 2; num <= 12; num++) {
  //  int yes = 0;
  //  vector<int> a(num);
  //  for (int i = 1; i <= num; i++) a[i - 1] = i;
  //  do {
  //    int flag = 1;
  //    for (int i = 0; i < num; i++) {
  //      if (a[i] == i + 1) {
  //        flag = 0;
  //        break;
  //      }
  //    }
  //    if (!flag) continue;
  //    for (int i = 1; i < num - 1; i++) {
  //      if (a[i - 1] == a[i] + 1 || a[i - 1] == a[i] - 1 || a[i + 1] == a[i] + 1 || a[i + 1] == a[i] - 1) continue;
  //      else {
  //        flag = 0;
  //        break;
  //      }
  //    }
  //    if (a[1] != a[0] + 1 && a[1] != a[0] - 1) flag = 0;
  //    if (a[num - 1] != a[num - 2] + 1 && a[num - 1] != a[num - 2] - 1) flag = 0;
  //    if (!flag) continue;
  //    else {
  //      
  //      for (int i : a) cout << i << " ";
  //      cout << endl;
  //      yes = 1;
  //      break;
  //    }
  //  } while (next_permutation(a.begin(), a.end()));
  //  if (!yes) cout << "Case #" << num << " no\n";
  //}
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

