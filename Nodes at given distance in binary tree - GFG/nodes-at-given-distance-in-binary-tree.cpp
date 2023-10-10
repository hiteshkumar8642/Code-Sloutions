//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    public:

 

    void traverse_child(Node* root, int curdist, int req_dist, vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(curdist == req_dist){
            ans.push_back(root->data);
            return ;
        }
        
        traverse_child(root->left, curdist+1, req_dist, ans);
        traverse_child(root->right, curdist+1, req_dist, ans);
        
        return;
    }

pair<bool, int> f(Node* root, int key, int dist, vector<int>&ans){
    if(root == NULL){
        return {false, -1};
    }
    if(root->data == key){
        traverse_child(root, 0, dist, ans);
        return {true, 0};
    }
    
    pair<bool, int> left = f(root->left, key, dist, ans);
    if(left.first == true){
        //comming to up from bottom left
        int curdist = 1 + left.second;
        if(curdist == dist){
            ans.push_back(root->data);
            return {true, curdist};
        }
        else if(curdist > dist){
            return {true, curdist};
        }
        else{
            //curdist is less so go right and check
            traverse_child(root->right, 0, dist - (curdist+1), ans);
            return {true, curdist};
        }
    }
    
    pair<bool, int> right = f(root->right, key, dist, ans);
    if(right.first == true){
        //coming up from bottom right
        int curdist = 1 + right.second;
        if(curdist == dist){
            ans.push_back(root->data);
            
            return {true, curdist};
        }
        else if(curdist > dist){
            return {true, curdist};
        }
        else{
            traverse_child(root->left, 0, dist - (curdist+1), ans);
            return {true, curdist};
        }
        
    }
    else{
        //didn't find the targeted node
        return {false, -1};
    }
    
    
}

 

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>ans;
        int dist = k;
        pair<bool, int> dummyans = f(root, target, dist, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends