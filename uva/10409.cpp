#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

int n;
vector<int> nums(6); // top, down, east, west, south, north

void solve()
{
  nums = {1, 6, 4, 3, 5, 2};
  string s; 
  for (int i = 0; i < n; i++) {
    cin >> s;
    int top;
    if (s == "north") {
      top = nums[0];
      nums[0] = nums[4];
      nums[4] = nums[1];
      nums[1] = nums[5];
      nums[5] = top;
    }
    else if (s == "east") {
      top = nums[0];
      nums[0] = nums[3];
      nums[3] = nums[1];
      nums[1] = nums[2];
      nums[2] = top;
    }
    else if (s == "south") {
      top = nums[0];
      nums[0] = nums[5];
      nums[5] = nums[1];
      nums[1] = nums[4];
      nums[4] = top;
    }
    else {
      top = nums[0];
      nums[0] = nums[2];
      nums[2] = nums[1];
      nums[1] = nums[3];
      nums[3] = top;
    }
  }
  cout << nums[0] << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  // int t = 1;
  // cin >> t;
  while (cin >> n && n != 0)
  {
    solve(); 
  }
  return 0;
}

