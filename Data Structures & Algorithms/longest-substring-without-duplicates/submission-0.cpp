class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> window;
        int l = 0;
        int maxLength = 0;

        for (int r = 0; r < s.size(); r++) {
            while (window.contains(s[r])) {
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
