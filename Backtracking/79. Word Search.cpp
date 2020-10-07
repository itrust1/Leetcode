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

