#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
  int n; cin >> n;
  priority_queue<int> a, b;
  int x;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    a.push(x);
  }
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    b.push(x);
  }
  int ans = 0;
  while (!a.empty())
  {
    if (a.top() == b.top()) {
      a.pop();
      b.pop();
      continue;
    }
    ans++;
    if (a.top() > b.top()) {
      a.push(to_string(a.top()).size());
      a.pop();
    } else {
      b.push(to_string(b.top()).size());
      b.pop();
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

