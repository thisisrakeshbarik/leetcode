class Solution {
public:
    int mySqrt(int x) {
        int l =1;
        int r = x;
        int ans = 0;
        if (x==0) return 0;
        while(l<=r){
            int m = l +(r-l)/2;
            long long sq = 1LL * m * m;
            if(sq==x) return m;
            else if(sq < x) {
                ans = m;
                l = m+1;
            }
            else {
                r = m-1;
            }

        }  
        return ans;
    }
};