class Solution {
public:
    int getChange(int n) {
        int res = 0;
        while (n > 0) {
            int m = n % 10;
            res += m * m;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        set<int> has;
        while (getChange(n) != 1) {
            n = getChange(n);
            if (has.find(n) != has.end())
                return false;
            has.insert(n);
        }
        return true;
    }
};
