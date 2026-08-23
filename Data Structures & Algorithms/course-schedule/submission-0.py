class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {i:[] for i in range(numCourses)}

        for edge in prerequisites:
            preMap[edge[0]].append(edge[1])

        visit = set()

        def dfs(node) -> bool:
            if node in visit:
                return False
            if preMap[node] == []:
                return True
            
            visit.add(node)
            for d in preMap[node]:
                if not dfs(d):
                    return False
            visit.remove(node)
            preMap[node] = []
            return True
        
        for crs in range(numCourses):
            if not dfs(crs):
                return False
        return True
            