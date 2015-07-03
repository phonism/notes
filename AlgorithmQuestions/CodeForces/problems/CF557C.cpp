#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 100010;

int n, tot;
pair<int, int> a[maxn];
multiset<int> st;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
        tot += a[i].second;
    }
    sort(a, a + n);
    int ans = ~0U >> 1;
    for (int i = 0; i < n; i++) {
        int j = i, sum = a[i].second;
        while (j + 1 < n && a[j+1].first == a[i].first)
            sum += a[++j].second;
        int cnt = j - i + 1;
        multiset<int>::reverse_iterator it = st.rbegin();
        for (int k = 0; k < cnt - 1 && it != st.rend(); k++, it++) {
            sum += *it;
        }
        ans = min(ans, tot - sum);
        for (int k = i; k <= j; k++) {
            st.insert(a[k].second);
        }
        i = j;
    }
    printf("%d\n", ans);
    return 0;
}
