class Solution {
public:
    int findClosest(int x, int y, int z) {
       int  min1 = abs(x-z);
       int  min2 = abs(y-z);
        if(min1 < min2) return 1;
        if(min2 < min1) return 2;
        else return 0;
        
    }
};