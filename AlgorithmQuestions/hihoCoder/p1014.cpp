#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

struct TrieNode {
    int son[26];
    int cnt;
    
    void init() {
        cnt = 0;
        memset(son, -1, sizeof(son));
    }
};

int tot;
TrieNode trie[1000000];

void insert(char *buf) {
    int cur = 0;
    for (int i = 0; buf[i]; i++) {
        if (trie[cur].son[buf[i]-'a'] == -1) {
            trie[tot].init();
            trie[cur].son[buf[i]-'a'] = tot++;
        }
        cur = trie[cur].son[buf[i]-'a'];
        trie[cur].cnt++;
    }
}

int query(char *buf) {
    int cur = 0;
    for (int i = 0; buf[i]; i++) {
        if (trie[cur].son[buf[i]-'a'] == -1) {
            return 0;
        }
        cur = trie[cur].son[buf[i]-'a'];
    }
    return trie[cur].cnt;
}

char buf[22];

int main() {
    int n, m;
    while (~scanf("%d", &n)) {
        trie[0].init();
        tot = 1;
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            insert(buf);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s", buf);
            printf("%d\n", query(buf));
        }
    }
    return 0;
}
