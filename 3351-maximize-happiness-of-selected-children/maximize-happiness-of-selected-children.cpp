class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long happy = 0;
        for (int i = 0; i < k; i++) {
            if (happiness[i] - i > 0)
                happy += happiness[i] - i;
        }
        return happy;
    }
};
