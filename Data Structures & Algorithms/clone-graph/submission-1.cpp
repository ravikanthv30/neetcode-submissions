/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//input is node and can traverse to depth 
//output is to get the node address back with smae list 
// copy program -> problem: i have to create nodes first and
// then add those addresses to the  neigh list & cycles ?
// edge cases: do we have cycles or reconnected items ?
// dfs recursive funciton or we can do level order bfs 
// dfs wont take much of extra space; bfs needs queue
// lets try DFS and Time complexity would be O(n)
class Solution {
public:
    unordered_map <Node*, Node*> um;
    Node* cloneGraph(Node* node) {
        
        //create a first dummy node and pass one to the DFS
        // dfs - will take node and clone , traverse each of the neighbors
        // what it returns is each clone node created.
        //return dfs(node);

     //it went wrong I think the actual problem is: neighbors can have the same node as you had already created... this is not a BST that nodes wont repeat kind !! :() 
        //need to have visited cases to create nodes;
        // use hashmap to have those list of nodes created ? but does the values all are unique  or duplicates ? if duplicates it would fail !! 
        //I think DFS wont work - we should do BFS ?
        if(node == nullptr)
            return nullptr;

        queue <Node*> q;
        q.push(node);
        Node * ret = new Node(node->val);
        um.insert({node, ret});

        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            //clone neighbors
            Node* clone = um[curr];

            for(int j=0; j<curr->neighbors.size(); j++)
            {
                Node* neighNode = curr->neighbors[j];
                if(neighNode == nullptr)
                    continue;
                Node* tempClone = nullptr;
                auto it = um.find(neighNode);
                if(it == um.end())
                {
                    //create a new node and store in um
                    tempClone = new Node(neighNode->val);
                    um.insert({neighNode, tempClone});
                    q.push(neighNode);
                }
                else
                {
                    tempClone = it->second;
                }
                clone->neighbors.push_back(tempClone);
            }
        }
        return ret;
    }

};
