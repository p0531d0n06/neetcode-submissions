class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0;
        int maxFreq = 0;   // max frequency of any single char in current window
        int maxLength = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // window size - most frequent char count = chars that need replacing
            while ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
