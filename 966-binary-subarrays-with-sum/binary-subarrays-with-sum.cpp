class Solution {
public:
int cntGoal(vector<int>& nums, int goal){
      int n = nums.size();
      int l = 0;
      int r = 0;
      int cnt = 0;
      long long sum = 0;
      while(r<n){
        sum+=nums[r];
        while(l<=r && sum>goal){
            sum-=nums[l];
            l++;
        }
        cnt += (r - l + 1);
        r++;
      }
      return cnt;
}

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int g1 = cntGoal(nums,goal);
        int g2 = cntGoal(nums,goal-1);
        return g1-g2;  
    }
};