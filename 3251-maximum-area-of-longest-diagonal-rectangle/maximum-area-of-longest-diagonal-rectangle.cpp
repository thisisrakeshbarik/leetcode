class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxD = -1;
        int maxA = -1;
        int n = dimensions.size();
        for(int i=0;i<n;i++){
            int width = dimensions[i][0];
            int height = dimensions[i][1];
            int Dsq = width*width + height*height;
            int Area = width*height;
            if(Dsq > maxD || ( Dsq ==maxD && Area > maxA)){
                maxD = Dsq;
                maxA = Area;
            }  
        }
        return maxA;
    }
};