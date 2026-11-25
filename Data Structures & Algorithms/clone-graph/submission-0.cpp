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
        return dfs(node);

     //it went wrong I think the actual problem is: neighbors can have the same node as you had already created... this is not a BST that nodes wont repeat kind !! :() 
        //need to have visited cases to create nodes;
        // use hashmap to have those list of nodes created ? but does the values all are unique  or duplicates ? if duplicates it would fail !! 
        //I think DFS wont work - we should do BFS ?
/*
        queue <Node*> q;
        q.push(node);
        Node * ret = new Node(node->val);
        um.insert({node, ret});

        while(!q.empty())
        {
            int len = q.size();

            for(int i=0; i<len; i++)
            {
                Node* curr = static_cast<Node*>( q.front());
                q.pop();
                auto it = um.find(curr);
                Node* clone = nullptr;
                if(it == um.end())
                {
                    //create a new node and store in um
                     clone = new Node(curr->val);
                    um.insert({curr, clone});
                }
                else
                   clone = it->second;
                
                for(int j=0; j<curr->neighbors.size(); j++)
                {
                    Node* neighNode = curr->neighbors[j];
                    auto it = um.find(neighNode);
                    if(it == um.end())
                    {
                        q.push(neighNode);
                    }
                    else 
                        clone->neighbors.push_back(it->second);
                }
            }
            
        }
        return ret;*/
    }
private:

    Node* dfs( Node* root)
    {
        if(root==nullptr)
            return nullptr;
        auto it = um.find(root);
        if( it != um.end())
            return it->second;

        //create a node
        int num = static_cast<int>(root->neighbors.size());
        Node* node = new Node(root->val);
        um.insert({root, node});

        for(int i=0; i<num; i++)
        {
            Node* temp = dfs(root->neighbors[i]);
            node->neighbors.push_back(temp);
        }
        return node;
    } 
};
