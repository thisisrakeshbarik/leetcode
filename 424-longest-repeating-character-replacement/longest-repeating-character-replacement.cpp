class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int r = 0;
        int l = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector <int> hashA(26,0);
        while(r<n){
            hashA[s[r]-'A']++;
            maxFreq = max(maxFreq,hashA[s[r]-'A']);
            if((r-l+1)-maxFreq > k){
                 hashA[s[l]-'A']--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;

        } 
        return maxLen;
    }
};