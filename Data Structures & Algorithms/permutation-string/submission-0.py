class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        charFreqS1 = []
        charFreqS2 = []

        for i in range(26):
            charFreqS1.append(0)
            charFreqS2.append(0)

        for c in s1:
            charFreqS1[ord(c) - ord('a')] += 1

        for i in range(len(s1)):
            index = ord(s2[i]) - ord('a');
            charFreqS2[index] += 1

        if charFreqS1 == charFreqS2:
            return True

        j = 0
        i = len(s1)
        while i < len(s2):
            charFreqS2[ord(s2[i]) - ord('a')] += 1
            charFreqS2[ord(s2[j]) - ord('a')] -= 1
            if charFreqS1 == charFreqS2:
                return True
            i+=1;
            j+=1;

        return False