class Solution:

    def getChange(self, n):
        res = 0
        while n > 0:
            m = n % 10
            res += m * m
            n /= 10
        return res

    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        has = set()
        has.add(n)
        while self.getChange(n) != 1:
            n = self.getChange(n)
            if n in has:
                return False
            has.add(n)
        return True

sol = Solution()

print sol.isHappy(7)
print sol.getChange(7)
