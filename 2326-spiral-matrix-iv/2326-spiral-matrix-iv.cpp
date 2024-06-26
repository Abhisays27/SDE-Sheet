/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        int top = 0;
        int bottom = n - 1;
        int right = m - 1;
        int left = 0;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        ListNode* temp = head;

        while (top <= bottom && left <= right && temp != nullptr) {
            for (int i = left; i <= right && temp != nullptr; i++) {
                ans[top][i] = temp->val;
                temp = temp->next;
            }
            top++;

            for (int i = top; i <= bottom && temp != nullptr; i++) {
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            if (top <= bottom && temp != nullptr) {
                for (int i = right; i >= left && temp != nullptr; i--) {
                    ans[bottom][i] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            }

            if (left <= right && temp != nullptr) {
                for (int i = bottom; i >= top && temp != nullptr; i--) {
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
        }

        return ans;
    }
};
