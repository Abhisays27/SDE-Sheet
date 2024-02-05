class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int cnt1 = 0, cnt2 = 0;
        int ls1 = INT_MIN, ls2 = INT_MIN;
        vector<int> result;

        for (int num : nums) {
            if (cnt1 == 0 && ls2 != num) {
                cnt1 = 1;
                ls1 = num;
            } else if (cnt2 == 0 && ls1 != num) {
                cnt2 = 1;
                ls2 = num;
            } else if (num == ls1) {
                cnt1++;
            } else if (num == ls2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        int minCount = nums.size() / 3;

        cnt1 = 0;
        cnt2 = 0;

        for (int num : nums) {
            if (num == ls1) cnt1++;
            if (num == ls2) cnt2++;
        }

        if (cnt1 > minCount) result.push_back(ls1);
        if (cnt2 > minCount) result.push_back(ls2);

        return result;
    }

       
       
    };
        

