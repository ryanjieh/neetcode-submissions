class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist = makeAdjList(numCourses, prerequisites);
        //implement topological sort by ... bfs?
        vector<int> indegs(numCourses);
        for (auto vect: prerequisites) {
            indegs[vect[1]] ++;
        };
        cout << "\n";
        vector<int> answer;
        queue<int> nodequeue;
        for (int i = 0; i < numCourses; i++) {
            if (indegs[i] == 0) {
                nodequeue.push(i);
            }
        };
        cout << nodequeue.size() << "\n";
        while(!nodequeue.empty()) {
            int u = nodequeue.front();
            //cout << u;
            answer.push_back(nodequeue.front());
            nodequeue.pop();
            for (auto v: adjlist[u]) {
                cout << "skibidi " << indegs[v];
                if (--indegs[v] == 0) {
                    nodequeue.push(v);
                    cout << nodequeue.size() << "siz seven \n"; 
                }
            }
        };
        vector<int> emptyv;
        if (answer.size() != numCourses) {
            return emptyv;
        } else {
            reverse(answer.begin(), answer.end());
            return answer;
        }
    }
    vector<vector<int>> makeAdjList(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for (auto prereq: prerequisites) {
            adjlist[prereq[0]].push_back(prereq[1]);
        };
        cout << adjlist[0].size() << " your mom gay\n";
        return adjlist;
    }
};
