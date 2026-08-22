class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        l = len(str(x))
        INT_MAX = pow(2,31) - 1
        INT_MIN = -pow(2, 31)

        if x > 0:
            for i in range(0, l):
                d = x % 10
                x = math.floor(x/10)
                if result > math.floor(INT_MAX / 10):
                    return 0
                result *= 10
                if result > INT_MAX - d:
                    return 0
                result += d
        else:
            for i in range(0, l-1):
                d = (x % 10);
                if d > 0:
                    d -= 10
                x = math.ceil(x/10)
                if result < math.ceil(INT_MIN / 10):
                    return 0
                result *= 10
                if result < INT_MIN + d:
                    return 0
                result += d
        
        return result