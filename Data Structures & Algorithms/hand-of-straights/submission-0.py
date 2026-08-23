class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize > 0:
            return False

        if groupSize == 1:
            return True
        
        hand = sorted(hand)

        memo = {}

        for i in hand:
            if i not in memo.keys():
                memo[i] = 1
            else: 
                memo[i] += 1

        while memo:
            x = min(memo.keys());
            for i in range(x,x+groupSize):
                if i not in memo.keys():
                    return False
                memo[i] -= 1
                if memo[i] == 0:
                    memo.pop(i)
        
        return True

        

        