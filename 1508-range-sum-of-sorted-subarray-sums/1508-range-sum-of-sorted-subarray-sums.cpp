class Solution {
    long mod = 1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long> sum;

        for(int i = 0; i < n; i++) {
            long currentSum = 0;
            for(int j = i; j < n; j++) {
                currentSum = (currentSum + nums[j]) % mod;
                sum.push_back(currentSum);
            }
        }

        sort(sum.begin(), sum.end());

        long result = 0;
        for (int k = left - 1; k < right; k++) {
            result = (result + sum[k]) % mod;
        }

        return result;
    }
};
