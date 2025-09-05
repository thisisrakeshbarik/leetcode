class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long remain = 1LL * num1 - 1LL * k * num2;
            if (remain < 0) continue;
            int bits = __builtin_popcountll(remain);
            if (bits <= k && k <= remain) {
                return k;
            }
        }
        return -1;
    }
};
