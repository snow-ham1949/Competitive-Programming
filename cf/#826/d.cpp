#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int maxm = 262144 + 5;
int p[maxm], n;

// [l, r)
int dq(int l, int r) {
  bool sorted = true;
  for (int i = l + 1; i < r; i++) {
    sorted &= (p[i - 1] < p[i]);
  }
  if (sorted) return 0;

  int mid = (l + r) >> 1;
  int ansl = dq(l, mid);
  if (ansl < 0) return -1;
  int ansr = dq(mid, r);
  if (ansr < 0) return -1;

  int ans = ansl + ansr;
  if (p[mid - 1] > p[mid]) {
    ans++;
    for (int i = l; i < mid; i++) {
      swap(p[i], p[i - l + mid]);
    }
  }

  sorted = true;
  for (int i = l + 1; i < r; i++) {
    sorted &= (p[i - 1] < p[i]);
  }
  if (!sorted) return -1;
  return ans;
}

void solve()
{
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  cout << dq(0, n) << endl;  
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

