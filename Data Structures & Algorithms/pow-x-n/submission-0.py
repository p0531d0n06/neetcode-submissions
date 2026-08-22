class Solution:
    def helper(self, x, n) -> float:
        if(n < 2):
            return x
        val = self.helper(x,n//2)
        val *= val
        if n%2 != 0:
            val *= x
        return val

    def myPow(self, x: float, n: int) -> float:
        if(x == 0):
            return 0
        if(n==0):
            return 1
        
        b = abs(n)
        result = self.helper(x, b)

        
        if n < 0:
            return 1 / result
        return result
