#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
 
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        sum += s[i] - '0';
    }
    puts(sum % 9 ? "No" : "Yes");
}
