class Solution {
public:
    int search(vector<int>& arr, int target) {
       int n=arr.size();
       int k=target;
        int s=0;
        int e=n-1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(arr[mid]==k) return mid;

            //if left part is sorted
            else if(arr[s]<=arr[mid]){
                if(k>=arr[s] && k<=arr[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }

            // right part m aya mid
            else{
               if(k>=arr[mid] && k<=arr[n-1]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }

        return -1;
   
        
    }
};