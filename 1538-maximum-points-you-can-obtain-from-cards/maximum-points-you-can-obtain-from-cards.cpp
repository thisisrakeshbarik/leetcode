class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum = 0;
        int rSum= 0;
        int maxi = 0;
        if(k==1) return max(cardPoints[0],cardPoints[n-1]);
        for(int i=0;i<k;i++){
            lSum+=cardPoints[i];
            maxi = lSum;
        }
        int rightIndex = n-1;
        for(int i=k-1;i>=0;i--){
            lSum -= cardPoints[i];
            rSum += cardPoints[rightIndex];
            rightIndex--;
            maxi = max(maxi,lSum+rSum);
        }

        return maxi;
    }
};