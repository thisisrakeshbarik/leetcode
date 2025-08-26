class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> seen(256, false);  
            int currLen = 0;

            for (int j = i; j < n; j++) {
                if (seen[s[j]]) {
                    break; 
                }
                seen[s[j]] = true;
                currLen++;
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};
