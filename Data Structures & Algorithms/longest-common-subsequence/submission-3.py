class Solution:

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        memo = [[0] * (len(text1)+1) for _ in range(len(text2)+1)]
        
        for i in range(1, len(text2)+1):
            for j in range(1, len(text1)+1):
                if(text1[j-1] == text2[i-1]):
                    memo[i][j] = memo[i-1][j-1] + 1
                else:
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1])

        return memo[len(text2)][len(text1)]
        
        