/* 
RECURSION
Idea - subset(1,2,3) = subset(1,2) + (for i's ( subset(1,2)[i].push_back(3) ))

Time complexity -  T(n) = T(n-1) + O(n*2^(n-1)) 
                => T(n) = O(n*2^n)
Space Complexity - O(n*2^n)

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0){
            result.push_back({});
            return result; 
        }
        int x = nums[nums.size()-1];
        nums.pop_back();
        result = subsets(nums);
        int s = result.size(); // have to store it, instead if you use result.size() in for loop then as you are adding elements to 
                               // result its size will keep on increasing and then TLE/MLE
        
        //O(n*2^(n-1))
        for(int i{}; i<s; i++){
            vector<int> to_add = result[i]; //O(result[i].size) copying 
            to_add.push_back(x);
            result.push_back(to_add);
        }
        return result;
    }
};
