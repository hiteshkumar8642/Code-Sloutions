//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    void order(Node * root,vector<int>& v){
    if(root==NULL){
        return ;
    }
    order(root->left,v);
    v.push_back(root->data);
    order(root->right,v);
    
}
    int floor(Node* root, int x) {
        // Code here
        vector<int> v;
        int ans=0;
        order(root,v);
        if(v[0]>x){
            return -1;
        }
        if(v[v.size()-1]<x){
            return v[v.size()-1];
        }
        else{
        int i=0;
        int e=v.size()-1;
        int mid=i+(e-i)/2;
        while(i<=e){
            if(v[mid]==x){
                ans=v[mid];
                break;
            }
            if( x<v[mid+1] && x>v[mid]){
                ans=v[mid];
                break;
            }
            if(x<v[mid]){
                e=mid-1;
            }
            else{
                i=mid+1;
            }
            mid=i+(e-i)/2;
        }
        return ans;
        }
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends