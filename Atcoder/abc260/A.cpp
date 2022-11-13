#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> num(26, 0);
    for (char c: s) {
        num[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (num[i] == 1) {
        printf("%c\n", i + 'a');
        exit(0);
        }
    }
    printf("-1\n");
  
  return 0;
}