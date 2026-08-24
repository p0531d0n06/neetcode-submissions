class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "" : return []

        numsT = {
            2 : "abc",
            3 : "def",
            4 : "ghi",
            5 : "jkl",
            6 : "mno",
            7 : "pqrs",
            8 : "tuv",
            9 : "wxyz",
        }

        res = []

        def dt(i, cur):
            if i >= len(digits):
                res.append(cur)
                return
            for c in numsT[int(digits[i])]:
                dt(i+1, cur + c)
        
        dt(0, "")
        return res
