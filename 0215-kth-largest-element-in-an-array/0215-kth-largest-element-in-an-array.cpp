class Solution {
    void heapify(vector<int>& nums,int n, int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;

        if(n>left && nums[largest]<nums[left]){
            largest=left;
        }
         if(n>right && nums[largest]<nums[right]){
            largest=right;
        }
        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=n/2;i>=0;i--){
            heapify(nums,n,i);
        }
      k = n - k + 1; // adjust k to find the kth largest element
    for(int i=n-1;i>=0;i--){
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
        if(i+1 == k) return nums[k-1];
    }
    return -1; // error handling
    }
};