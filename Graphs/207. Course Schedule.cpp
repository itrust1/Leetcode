We have to build a graph with nodes as a course and `(u,v)` as directed edges, `(u,v)` means `u` is a prerequisite for `v`. Building of a graph can be done using one `for` loop. Then we need to find whether there is a cycle in a graph or not, as if there is a cycle then it is not logical allocation of prerequisites. 


#  DFS
- The main idea how this works - while exploring a particular node, if you encounter a visited node which is not completely explored then there is a cycle. *Carry on reading if the idea is not clear*.

We will have two boolean arrays- `visited` and `isexplored`. Lets explore `u`, as soon as we have explored all the nodes that are reachable from u i.e. we complete `for` loop for node `u`, we mark `u` as explored (`isexplored[u]=1`). Now lets say while exploring `x`, we encounter a node `y` such that `visited[y]=1` and`isexplroed[y]=0`, that means `y` is still getting explored. And we are in state of exploring `y` which have lead us to `x` but `x` is having edge to `y`, that is both are reachable from each other, and we call it cycle. *feww.. tried my best to explain but not sure if it is good.*
 ```
class Solution {
public:
    //          DFS 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0; i<prerequisites.size(); ++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false), isexplored(numCourses, false);
        bool ans=true;
        for(int i=0; i<numCourses; ++i){
            if(visited[i]==false)
                dfs(i, graph, visited, isexplored, ans);
            if(ans == false)
                break;
        }
        return ans;
    }
    void dfs(int i, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& isexplored, bool& ans){
        visited[i] = true;
        for(int x: graph[i]){
            if(visited[x]==false)
                dfs(x, graph, visited, isexplored, ans);
            if(visited[x]==true && isexplored[x]==false){
                ans = false;
                return;
            }
        }
        isexplored[i] = true;
    }
};
```

# BFS 
as given in hint 3
[https://en.wikipedia.org/wiki/Topological_sorting#Algorithms](http://)
I will try to explain why this works.
- we find all nodes with indegree 0, why? and then?
	- the edges coming out from this node can't be a part of cycle for sure. As nodes are having indegree 0 i.e. you can't reach back to that node after traveling.
	- so you can just remove those nodes and see if the remaining graph has cycle. Do apply the same procedure for that. 

```
class Solution {
public:
    //          BFS 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0; i<prerequisites.size(); ++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegrees = computeIndegrees(graph);
        // vector<int> toposort;
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
            if(indegrees[i]==0)
                q.push(i);
        while(!q.empty()){
            int front = q.front();
            // toposort.push_back(front);
            q.pop();
            for(int x:graph[front]){
                indegrees[x]--;
                if(indegrees[x]==0)
                    q.push(x);
            }
        }
        
        for(int i=0; i<numCourses; ++i){
            if(indegrees[i]!=0)
                return false;
        }
        // for(int i=0; i<numCourses; ++i)
        //     cout<<toposort[i]<<" ";
        return true;
    }

    
    vector<int> computeIndegrees(vector<vector<int>>& graph ){
        vector<int> indegrees(graph.size(),0);
        for(int i=0; i<graph.size(); ++i){
            for(int j=0; j<graph[i].size(); ++j){
                indegrees[graph[i][j]]++;
            }
        }    
        return indegrees;
        
    }
    
};
```
