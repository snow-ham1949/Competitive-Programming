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
  vector<pair<double, double>> v(4);
  while (cin >> v[0].X >> v[0].Y >> v[1].X >> v[1].Y >> v[2].X >> v[2].Y >> v[3].X >> v[3].Y) {
    set<pair<double, double>> st;
    int duplicate = -1;
    for (int i = 0; i < 4; i++) {
      if (st.find(v[i]) != st.end()) {
        duplicate = i;
        st.erase(st.find(v[i]));
      }
      else {
        st.insert(v[i]);
      }
    }

    vector<pair<double, double>> diagonal;
    for (int i = 0; i < 4; i++) {
      if (st.find(v[i]) != st.end()) diagonal.push_back(v[i]);
    }
    pair<double, double> ans;
    ans.X = diagonal[0].X + diagonal[1].X - v[duplicate].X;
    ans.Y = diagonal[0].Y + diagonal[1].Y - v[duplicate].Y;

    cout << fixed << setprecision(3) << ans.X << " " << ans.Y << "\n";
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

