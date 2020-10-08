// Backtracking
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0)
            return result;
        unordered_map<int,string> mp;
        string alphas = "abcdefghijklmnopqrstuvwxyz";
        int j = 0;
        for(int i=2; i<=9; ++i){
            if(i==7 || i==9){
                mp[i] = alphas.substr(j,4);
                j+=4;
            }
            else{
                mp[i] = alphas.substr(j,3);
                j+=3;
            }
        }
        string s;
        backtrack(0, digits, mp, s, result);
        return result;
    }
    void backtrack(int ind, string& digits, unordered_map<int,string>& mp, string& s, vector<string>& result){
        if(s.length()==digits.length()){
            result.push_back(s);
            return;
        }
        for(auto x: mp[digits[ind]-'0'] ){
            s.push_back(x);
            backtrack(ind+1, digits, mp, s, result);
            s.pop_back();
        }
    }
};




// Iterative 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0)
            return result;
        unordered_map<int,string> mp;
        string alphas = "abcdefghijklmnopqrstuvwxyz";
        int j = 0;
        for(int i=2; i<=9; ++i){
            if(i==7 || i==9){
                mp[i] = alphas.substr(j,4);
                j+=4;
            }
            else{
                mp[i] = alphas.substr(j,3);
                j+=3;
            }
        }
        
        queue<pair<string,int>> q;
        for(auto x:mp[digits[0]-'0']){
            string s = {};
            s.push_back(x);
            q.push(make_pair(s,1));
        }
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            if(p.second==digits.length()){
                result.push_back(p.first);
            }
            else{
                for(auto x:mp[digits[p.second]-'0'] ){
                    string s1 = p.first;
                    s1.push_back(x);
                    q.push(make_pair(s1,p.second+1));
                }
            }
        }
        return result;
        
    }
};
