class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        cleaned = []
        for i in range(len(triplets)):
            if triplets[i][0] <= target[0] and triplets[i][1] <= target[1] and triplets[i][2] <= target[2]:
                cleaned.append(triplets[i].copy())
        
        c = [False, False, False]

        for triplet in cleaned:
            if triplet[0] == target[0]:
                c[0] = True
            if triplet[1] == target[1]:
                c[1] = True
            if triplet[2] == target[2]:
                c[2] = True
            
            if c[0] and c[1] and c[2]:
                return True
        
        return False