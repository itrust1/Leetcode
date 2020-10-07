/*
bfs is not the correct algorithm to solve this problem.

The leetcode's judge test case where bfs didn't work
    A B C E
    S F E S 
    A D E E
    "ABCESEEEFS"


some my own examples where bfs fails
lets take 
    A B C 
    B E D
find if there is "ABCDEB" in the board, it is there but if you do bfs then both B will be marked visited and then while finding unvisited neighbours of E
you won't visit B([1,0]) again. May be you can mark that cell unvisited as you couldn't find the word in that path but take larger case and see.

    A B C 
    B F D
    C E D
    
find if there is "ABCDDECB", here you have to mark B and C unvisited as you couldn't find word in that path. Which I think can't be done or very cumbersome.
*/



/*
BACKTRACKING

Time Complexity - 


improvement by reading other posts - instead of using visited array, you can just do board[r][c] = *(some character other than alphabet) 
                                     and later board[r][c] = word[char_ind+1]
*/
class Solution {
public:
    int arr1[4] = {1,-1,0,0};
    int arr2[4] = {0,0, 1,-1};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[i].size(); ++j){
                if(board[i][j]==word[0]){
                    int flag = 0;
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false) );
                    visited[i][j] = true;
                    backtrack(i, j, 0, board, word, visited, flag);
                    if(flag==1)
                        return true;
                }
            }
        }
        return false;
    }
    void backtrack(int i, int j, int char_ind, vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int& flag){
        if(flag == 1)
            return;
        if(char_ind == word.length()-1){
            flag = 1;
            return;
        }
        for(int x=0; x<=3; ++x){
            int r = i + arr1[x];
            int c = j + arr2[x];
            if(r>=0 && r<board.size() && c>=0 && c<board[r].size() && board[r][c] == word[char_ind+1] && visited[r][c] == false){
                visited[r][c] = true;
                backtrack(r,c,char_ind+1, board, word, visited, flag);
                visited[r][c] = false;
            }
            
        }
    }
};
