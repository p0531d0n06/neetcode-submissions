class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxL = 0
        maxLs = 0

        # odd
        for i in range(0, len(s)):
            j = i
            k = i
            while j >= 0 and k < len(s):
                if s[j] == s[k]:
                    if k-j+1 > maxL:
                        maxL = k-j+1
                        maxLs = j
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
                    if k-j+1 > maxL:
                        maxL = k-j+1
                        maxLs = j
                else:
                    break
                j-=1
                k+=1 

        return s[maxLs:maxLs+maxL]
            