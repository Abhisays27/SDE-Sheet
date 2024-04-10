class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size();
        int b=nums2.size();

        if(a>b){
            return findMedianSortedArrays( nums2,  nums1);
        }

        int s=0;
        int e=a;
        int left=(a+b+1)/2;
        int n=a+b;

        while(s<=e){
            int mid1=(s+e)>>1;
            int mid2=left-mid1;

     

            int l1=mid1==0?INT_MIN:nums1[mid1-1];
            int l2=mid2==0?INT_MIN:nums2[mid2-1];
            int r1=mid1==a?INT_MAX:nums1[mid1];
           int r2=mid2==b?INT_MAX:nums2[mid2];

            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
                else{
                    return((double)(max(l1, l2) + min(r1, r2))) / 2.0;

                }
            }
            else if(l1>r2){
                e=mid1-1;
            }
            else {
                s=mid1+1;
            }

        }
        return 0;
        
    }
};