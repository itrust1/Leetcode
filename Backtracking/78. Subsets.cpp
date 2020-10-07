class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0){
            vector<int> to_add;
            result.push_back(to_add);
            return result; 
        }
        int x = nums[nums.size()-1];
        nums.pop_back();
        result = subsets(nums);
        int s = result.size();
        for(int i{}; i<s; i++){
            vector<int> to_add = result[i];
            to_add.push_back(x);
            result.push_back(to_add);
        }
        return result;
        
    }
};
