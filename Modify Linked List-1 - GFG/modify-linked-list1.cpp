//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        
        struct Node *slow_ptr = head;
        struct Node *fast_ptr = head->next;
 
        if (head!=NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
        
        }
        
        Node *mid=slow_ptr,*tail;
        //cout<<mid->data<<endl;
        Node* current = mid;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        tail = prev;
        int t;
        Node * temp1=head,*temp2=tail;
        while(temp2!=mid)
        {
            t=temp1->data;
            temp1->data=temp2->data-temp1->data;
            temp2->data=t;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        current = tail;
        prev = NULL;
        next = NULL;
 
        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        //cout<<mid->data<<endl;
        return head;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends