//Brute Force Approach
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = -1;
        int last = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == target) {

                if(first == -1)
                    first = i;
                
                last = i;
                
            }
        }

        return {first, last};
    }
};

//Optimal Approach
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int first=-1;
        int second=-1;
        int start=0;
        int end=arr.size()-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        start=0;
        end=arr.size()-1;
           while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target){
                second=mid;
                start=mid+1;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
     return {first,second};
    }
};