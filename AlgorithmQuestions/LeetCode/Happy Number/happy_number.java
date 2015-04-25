public class Solution {

    public int getChange(int n) {
        int res = 0;
        while (n > 0) {
            int m = n % 10;
            res += m * m;
            n /= 10;
        }
        return res;
    }

    public boolean isHappy(int n) {
        HashSet<Integer> has = new HashSet<Integer>();
        has.add(n);
        while (getChange(n) != 1) {
            n = getChange(n);
            if (has.contains(n))
                return false;
            has.add(n);
        }
        return true;
    }
}
