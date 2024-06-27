class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;
        int leftMax = -1;
        int rightMax = -1;
        int res = 0;

        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if (leftMax < rightMax) {
                res += leftMax - height[l];
                l++;
            } else {
                res += rightMax - height[r];
                r--;
            }
        }

        return res;
    }
};