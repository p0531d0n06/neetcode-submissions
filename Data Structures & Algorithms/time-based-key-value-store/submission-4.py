class TimeMap:

    def __init__(self):
        self.store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        a = self.store.setdefault(key, [])
        self.store[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        res = ""
        vals = self.store.get(key,[])
        i = 0
        j = len(vals) - 1

        while i <= j:
            m = (i+j) // 2
            if vals[m][1] <= timestamp:
                res = vals[m][0]
                i = m+1
            else:
                j = m-1
        
        return res
        
