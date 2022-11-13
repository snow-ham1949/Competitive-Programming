#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int) a.size()
#define endl '\n'
#define X first
#define Y second
#define MAXN 3000006
int trie[MAXN][65], cnt[MAXN], idx = 0;
char s[MAXN];

int getindex(char a){ // A~Z, a~z, 0~9
  if(a >= 'A' && a <= 'Z') return a - 'A';
  if(a >= 'a' && a <= 'z') return a - 'a' + 26;
  return a - '0' + 52;
}

void insert(char *str){
  int rt = 0, len = strlen(str);
  for(int i = 0; i < len; i++){
    int index = getindex(str[i]);
    if(!trie[rt][index]){
      idx++;
      trie[rt][index] = idx;
    }
    rt = trie[rt][index];
    cnt[rt] ++;
  }
}

int find(char *str){
  int rt = 0, len = strlen(str);
  for(int i = 0; i < len; i++){
    int index = getindex(str[i]);
    if(!trie[rt][index]) return 0;
    rt = trie[rt][index];
  }
  return cnt[rt];
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    for(int i=0;i<=idx;i++)
      for(int j=0;j<=122;j++)
        trie[i][j]=0;
    for(int i=0;i<=idx;i++)
      cnt[i]=0;
    idx=0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
      scanf("%s",s);
      insert(s);
    }
    for(int i=1;i<=q;i++){
      scanf("%s",s);
      printf("%d\n",find(s));
    }      
  }
  return 0;
}
