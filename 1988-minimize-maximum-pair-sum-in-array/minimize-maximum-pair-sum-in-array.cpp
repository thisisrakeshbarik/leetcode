class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxSum = 0;
        for(int i=0; i<n ; i++){
            maxSum = max(maxSum, nums[i]+nums[n-1-i]);
        }
        return maxSum;
    }
};