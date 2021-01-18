#include <bits/stdc++.h>
using namespace std;

string s;
string b[8];
int ans = 0;
bool already[8];
bool zuoxie[128];
bool youxie[128];

void dfs(int num) {
    if (num == 8) {
        ans++;
        return ;
    }

    for (int i = 0; i < 8; ++i) {
        if (b[num][i] == '.') {
            if (already[i]) {
                continue;
            }
            if (zuoxie[num + i]) {
                continue;
            }
            if (youxie[8 + num - i - 1]) {
                continue;
            }
            already[i] = true;
            zuoxie[num + i] = true;
            youxie[8 + num - i - 1] = true;
            dfs(num + 1);
            already[i] = false;
            zuoxie[num + i] = false;
            youxie[8 + num - i - 1] = false;
        
        }
    }
}

int main() {
    for (int i = 0; i < 8; ++i) {
        cin >> b[i];
    }
    dfs(0);
    cout << ans << endl;
}
