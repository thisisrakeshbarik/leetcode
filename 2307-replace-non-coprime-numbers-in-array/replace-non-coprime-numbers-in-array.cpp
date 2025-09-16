class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;  // stack simulation
        for (int num : nums) {
            st.push_back(num);
            
            // keep merging while last two are non-coprime
            while (st.size() > 1) {
                int b = st.back(); 
                int a = st[st.size() - 2];
                int g = gcd(a, b);
                if (g == 1) break; // coprime, stop merging
                
                long long lcm = 1LL * a / g * b; // avoid overflow
                st.pop_back();
                st.back() = (int)lcm;
            }
        }
        return st;
    }
};
