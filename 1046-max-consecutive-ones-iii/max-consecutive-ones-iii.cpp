class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r<n){
            if(nums[r]==1) r++;
            else if(nums[r]==0 && k!=0){
                r++;
                k--;
            }
            else if((nums[r]==0)&&(nums[l]==0)){
                    l++;
                    k++;
            }
            else{
                l++;
            }
            maxi = max(r-l,maxi);
        }

        return maxi;
    }
};