//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

typedef pair<double,double> pdd;
const double eps=1e-16;
pdd operator+(const pdd &a, const pdd &b)
{ return pdd(a.X + b.X, a.Y + b.Y);}
pdd operator-(const pdd &a, const pdd &b)
{ return pdd(a.X - b.X, a.Y - b.Y);}
pdd operator*(const pdd &a, const double &b)
{ return pdd(a.X * b, a.Y * b);}
pdd operator/(const pdd &a, const double &b)
{ return pdd(a.X / b, a.Y / b);}
double dot(const pdd &a,const pdd &b)
{ return a.X * b.X + a.Y * b.Y;}
double cross(const pdd &a,const pdd &b)
{ return a.X * b.Y - a.Y * b.X;}
int sign(const double &a)
{ return fabs(a) < eps ? 0 : a > 0 ? 1 : -1;}
int ori(const pdd &a,const pdd &b,const pdd &c)
{ return sign(cross(b - a, c - a));}
double abs2(const pdd &a)
{ return dot(a, a);}

void convex_hull(vector<pdd> &dots) { 
  sort(dots.begin(), dots.end());
  vector<pdd> ans(1, dots[0]);
  for (int ct = 0; ct < 2; ++ct, reverse(dots.begin(), dots.end()))
    for (int i = 1, t = SZ(ans); i < SZ(dots); ans.push_back(dots[i++]))
      while (SZ(ans) > t && ori(ans[SZ(ans) - 2], ans.back(), dots[i]) <= 0)
        ans.pop_back();
  ans.pop_back(), ans.swap(dots);
}

int rotating_calipers(vector<pdd> &hull) {
  double ans = 0.0;
  int t = 1;
  int sz = SZ(hull);
  hull.push_back(hull[0]);
  for (int i = 0; i < sz; i++) {
    while (cross(hull[i + 1] - hull[i], hull[t + 1] - hull[i]) > cross(hull[i + 1] - hull[i], hull[t] - hull[i])) t = (t + 1) % sz;
    ans = max(ans, max(abs2(hull[i] - hull[t]), abs2(hull[i + 1] - hull[t + 1])));
  }
  return (int)ans;
}

void solve()
{
  int n; cin >> n;
  vector<pdd> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].X >> p[i].Y;
  }
  convex_hull(p);
  cout << rotating_calipers(p) << endl;
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

