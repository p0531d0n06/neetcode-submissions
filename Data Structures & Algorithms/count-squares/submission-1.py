class CountSquares:

    def __init__(self):
        self.memo = {}

    def add(self, point: List[int]) -> None:
        if (point[0], point[1]) not in self.memo.keys():
            self.memo[(point[0], point[1])] = 0
        self.memo[(point[0], point[1])] += 1        

    def count(self, point: List[int]) -> int:
        res = 0

        for k in self.memo.keys():
            if abs(point[0] - k[0]) == abs(point[1] - k[1]) and abs(point[1] - k[1]) > 0:
                if (point[0], k[1]) in self.memo.keys() and (k[0],point[1]) in self.memo.keys():
                    res += self.memo[(k[0], k[1])] * self.memo[(point[0], k[1])] * self.memo[( k[0],point[1])]

        return res  
        
