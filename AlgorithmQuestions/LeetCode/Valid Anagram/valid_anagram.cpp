class Solution {
public:
    bool isAnagram(string s, string t) {
        int countS[30], countT[30];
        memset(countS, 0, sizeof(countS));
        memset(countT, 0, sizeof(countT));
        for (int i = 0; i < s.length(); i++) {
            countS[s[i]-'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            countT[t[i]-'a']++;
        }
        for (int i = 0; i < 30; i++) {
            if (countS[i] != countT[i])
                return false;
        }
        return true;
    }
};
