class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int maxi = 0;

        while (r < n) {
            if (nums[r] == 0) {
                k--;   // use a flip
            }

            // shrink window until valid
            while (k < 0) {
                if (nums[l] == 0) {
                    k++;  // release a flip
                }
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};
