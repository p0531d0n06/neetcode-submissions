class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        memo = []
        
        def trace(seg):
            if(len(seg)==n*2):
                memo.append(seg[::])
                return
            
            openC = 0
            closeC = 0

            for c in seg:
                if c == '(':
                    openC += 1
                else:
                    closeC += 1

            if openC < n:
                trace(seg + "(")
            if closeC < openC:
                trace(seg + ")")
        
        trace("")
        return memo
