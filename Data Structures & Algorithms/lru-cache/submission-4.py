class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
        self.lruKey = []

    def get(self, key: int) -> int:
        if key in self.cache.keys():
            self.lruKey.remove(key)
            self.lruKey.append(key)
            return self.cache[key]
        return -1

    def put(self, key: int, value: int) -> None:
        if key not in self.cache.keys():
            self.lruKey.append(key)
        else:
            self.lruKey.remove(key)
            self.lruKey.append(key)
        self.cache[key] = value
        if(len(self.lruKey) > self.cap):
            self.cache.pop(self.lruKey[0])
            self.lruKey.pop(0)
        
        
