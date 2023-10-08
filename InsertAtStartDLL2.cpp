//Doubly linked list
//How to insert at the start
#include<iostream>
using namespace std;

class Node{
	
	public:
		int val;
		Node* prev;
		Node* next; 
		
		Node(int data){
			val=data;
			prev=NULL;
			next=NULL;
		}
};

class DoublyLL{
	
	public:
		 Node* head;
		 Node* tail;
		 
		 DoublyLL(){
		 	head=NULL;
		 	tail=NULL;
		 }
		void display(){
			Node* temp=head;
			while(temp!=NULL){
				cout<<temp->val<<"<->";
				temp=temp->next;
			}
			cout<<endl;
		} 
		 
		
	void insertathead(int val){
		Node* new_node=new Node(val);
		
		if(head==NULL){
			head=new_node;
			tail=new_node;
			return;
		}
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
		return;
	}
		 
};


int main(){
	Node* new_node=new Node(3);
	
	DoublyLL dll;
	dll.insertathead(1);
	dll.insertathead(2);
	dll.insertathead(3);
	dll.display();
	
	return 0;
}
