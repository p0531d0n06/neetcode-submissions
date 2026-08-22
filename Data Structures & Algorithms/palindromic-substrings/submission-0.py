class Solution:
    def countSubstrings(self, s: str) -> int:
        c = 0

        # odd
        for i in range(0, len(s)):
            j = i
            k = i
            while j >= 0 and k < len(s):
                if s[j] == s[k]:
                    c+=1
                else:
                    break
                j-=1
                k+=1

        # odd
        for i in range(0, len(s)):
            j = i
            k = i+1
            while j >= 0 and k < len(s):
                if s[j] == s[k]:
                    c+=1
                else:
                    break
                j-=1
                k+=1 

        return c