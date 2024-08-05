#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;  // Stores elements

        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            // Remove elements from the back of deque if they are smaller than the current element
            while (!dq.empty() && dq.back() < nums[j]) {
                dq.pop_back();
            }

            // Add the current element to the deque
            dq.push_back(nums[j]);

            // If the window size is smaller than k, just increment j
            if (j - i + 1 < k) {
                j++;
            }
            // If the window size is exactly k
            else if (j - i + 1 == k) {
                // The element at the front of the deque is the maximum for this window
                ans.push_back(dq.front());

                // Remove the element going out of the window from the deque
                if (dq.front() == nums[i]) {
                    dq.pop_front();
                }

                // Slide the window forward
                i++;
                j++;
            }
        }

        return ans;
    }
};
