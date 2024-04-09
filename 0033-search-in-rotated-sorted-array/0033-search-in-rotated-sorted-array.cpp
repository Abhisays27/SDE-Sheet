class Solution {
    int getPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return mid + 1;
            } else if (nums[mid] > nums[s]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        int n = nums.size() - 1;
        if (target >= nums[pivot] && target <= nums[n]) {
            return binarySearch(nums, pivot, n, target);
        } else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};
