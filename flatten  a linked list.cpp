/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* head,Node* right){
	
	Node* ans=new Node(-1);
	Node* temp= ans;
	while(head!=NULL && right!=NULL){
		if(head->data<=right->data){
			temp->child=head;
			temp=head;
			head=head->child;
		}
		else{
			temp->child=right;
			temp=right;
			right=right->child;
		}
	}
	while(head!=NULL){
		temp->child=head;
		temp=head;
		head=head->child;
	}
	while(right!=NULL){
		temp->child=right;
		temp=right;
		right=right->child;
	}
	ans=ans->child;
	return ans;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	
	Node* right=flattenLinkedList(head->next);
    head->next=NULL;
    Node* ans=merge(head,right);
	return ans;

}
}
