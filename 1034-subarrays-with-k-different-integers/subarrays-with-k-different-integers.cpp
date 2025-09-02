class Solution {
public:
int atMost(vector<int>& nums, int k){
    int n=nums.size();
    int l=0 , r=0;
    int cnt = 0;
    map<int,int> mpp;
    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cntK = atMost(nums,k);
        int cntK1 = atMost(nums,k-1);
        return cntK-cntK1;
    }
};