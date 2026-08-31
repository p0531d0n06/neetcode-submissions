class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        traversed = []
        def dfs(x, y, i):
            if i >= len(word):
                return True
            if (x,y) in traversed:
                return False
            if x < 0 or y < 0 or x >= len(board[0]) or y >= len(board):
                return False
            if board[y][x] != word[i]:
                return False
            
            traversed.append((x,y))

            res = dfs(x-1, y, i+1) or dfs(x+1, y, i+1) or dfs(x, y+1, i+1) or dfs(x, y-1, i+1)
            traversed.pop()
            return res

        for y in range(len(board)):
            for x in range(len(board[0])):
                traversed = []
                if dfs(x, y, 0):
                    return True
        
        return False
        