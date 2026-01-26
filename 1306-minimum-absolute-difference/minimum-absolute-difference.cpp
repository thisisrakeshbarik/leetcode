class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int mindiff = INT_MAX;
        for(int i=1; i<arr.size();i++){
            mindiff = min(mindiff, arr[i]-arr[i-1]);
        }
        vector<vector<int>> result;
        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];

            if (diff == mindiff){
                result.push_back({arr[i-1],arr[i]});
            }
        }
        return result;
        
    }
};