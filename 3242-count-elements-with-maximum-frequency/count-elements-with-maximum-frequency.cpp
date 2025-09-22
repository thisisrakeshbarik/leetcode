class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mpp;
        int maxi = 0;
        for(int i = 0; i<nums.size();i++){
            mpp[nums[i]]+=1;
        }
        for(auto &it : mpp){
            maxi = max(it.second,maxi);
        }
        int sum = 0;
          for(auto &it : mpp){
            if(it.second == maxi)
            sum+=maxi;
        }
        return sum;
    }
};