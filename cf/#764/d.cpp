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
  int n, k;
  cin >> n >> k;
  string s; 
  cin >> s;
  vector<int> cnt(26, 0);
  for (char c : s) cnt[c - 'a']++;
  int total1 = 0, total2 = 0;
  for (int i = 0; i < 26; i++) total1 += cnt[i] / 2;
  for (int i = 0; i < 26; i++) total2 += cnt[i] % 2;
  int ans = total1 / k * 2;
  if (total1 % k * 2 + total2 >= k) ans++;
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

