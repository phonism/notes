#include <bits/stdc++.h>
using namespace std;

vector<int> vec, ans;

bool vis[10];
unordered_map<string, int> mp;
vector<string> res;
int cnt = 0;

void dfs(int num) {
    if (num == vec.size()) {
        string tmp = "";
        for (int i = 0; i < ans.size(); ++i) {
            tmp += ans[i] + 'a';
        }
        if (mp.find(tmp) == mp.end()) {
            res.push_back(tmp);
            cnt += 1;
        }
        mp[tmp] = 1;
        return ;
    }
    for (int i = 0; i < vec.size(); ++i) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        ans.push_back(vec[i]);
        num += 1;
        dfs(num);
        num -= 1;
        ans.pop_back();
        vis[i] = false;
    }
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        vec.push_back(s[i] - 'a');
    }
    sort(vec.begin(), vec.end());
    dfs(0);
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        cout << res[i] << endl;
    }

}
