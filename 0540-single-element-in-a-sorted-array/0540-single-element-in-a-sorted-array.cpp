class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
         int n = arr.size();
        if (n == 1) 
            return arr[0];

        // Check the first element
        if (arr[0] != arr[1]) 
            return arr[0];
        
        // Check the last element
        if (arr[n - 1] != arr[n - 2]) 
            return arr[n - 1];
        
        // Binary search
        int s = 1; 
        int e = n - 2;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            // Check if the current element is the single element
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) 
                return arr[mid];
            
            // Adjust the search range based on the position of the single element
            if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1])) 
                s = mid + 1;
            else 
                e = mid - 1;
        }
        
        return -1; // Single element not found
    }
    };