class Solution {
    void merge(vector<int> &nums, int s, int m, int e){
        vector<int> temp;

        int l = s;
        int r = m+1;

        while(l<=m && r<=e){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
                temp.push_back(nums[r]);
                r++;
            }
        }

        while(l<=m){
             temp.push_back(nums[l]);
                l++;

        }

        while(r<=e){
             temp.push_back(nums[r]);
                r++;

        }

        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
    }

    void mergeSort(vector<int> &nums, int s, int e){

        if(s>=e) return;


        int m = s + (e-s)/2;

        //left half
        mergeSort(nums,s,m);
        mergeSort(nums,m+1,e);

        merge(nums,s,m,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
      mergeSort(nums,0,n-1);
      return nums;
    }
};