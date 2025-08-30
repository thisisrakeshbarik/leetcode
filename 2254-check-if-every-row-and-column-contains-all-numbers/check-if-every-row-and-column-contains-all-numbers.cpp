class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // check rows
        for (int i = 0; i < n; i++) {
            vector<bool> seen(n+1, false);
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (val < 1 || val > n || seen[val]) 
                    return false; // invalid or duplicate
                seen[val] = true;
            }
        }

        // check columns
        for (int j = 0; j < n; j++) {
            vector<bool> seen(n+1, false);
            for (int i = 0; i < n; i++) {
                int val = matrix[i][j];
                if (val < 1 || val > n || seen[val]) 
                    return false; // invalid or duplicate
                seen[val] = true;
            }
        }

        return true;
    }
};
