class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(),nums.end());
        return first + nums[0]+ nums[1];

        
    }
};