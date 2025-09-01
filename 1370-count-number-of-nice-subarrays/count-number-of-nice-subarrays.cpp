class Solution {
public:
int cntGoal(vector<int>& nums, int goal){
      int n = nums.size();
      int l = 0;
      int r = 0;
      int cnt = 0;
      long long sum = 0;
      while(r<n){
        sum+=nums[r]%2;
        while(l<=r && sum>goal){
            sum-=nums[l]%2;
            l++;
        }
        cnt += (r - l + 1);
        r++;
      }
      return cnt;
}
 
    int numberOfSubarrays(vector<int>& nums, int k) {
        int g1 = cntGoal(nums,k);
        int g2 = cntGoal(nums,k-1);
        return g1-g2; 
    }
};