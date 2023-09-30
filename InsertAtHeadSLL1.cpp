//Node insert at any given position
#include<iostream>
using namespace std;

class Node{
	public:
		int val;
		Node* next;
		
		Node(int data){
			val=data;
			next=NULL;
		}
};
void insertathead(Node* &head,int val){
	Node* new_node=new Node(val);//
	new_node->next=head;
	head=new_node;
}



void display(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->val<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
Node* head=NULL;
insertathead(head,2);
display(head);
insertathead(head,1);
display(head);
	return 0;
} 
