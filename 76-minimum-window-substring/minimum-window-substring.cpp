class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int cnt = 0;
        int minLen = INT_MAX;
        int sInd = -1;
        vector<int> hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int l=0;
        int r=0;
        while(r<n){
            if(hash[s[r]]>0){
                cnt++;
            }
             hash[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sInd = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sInd == -1 ? "" : s.substr(sInd,minLen); 
        
    }
};