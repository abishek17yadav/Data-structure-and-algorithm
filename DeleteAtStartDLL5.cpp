//Doubly linked list
//how to delete at start;
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
	
	void insertatend(int val){
		Node* new_node=new Node(val);
		if(tail==NULL){
			head=new_node;
			tail=new_node;
			return;
		}
		tail->next=new_node;
		new_node->prev=tail;
		tail=new_node;
		return;
	}
	
	void insertatpos(int val,int k){
		//Assuming K is less or equal to  length of doublly linked list
		Node* temp=head;
		int count=1;
		while(count < (k-1)){
			temp=temp->next;
			count++;
		}
		//temp will be pointing to node at k-1 pos
		Node* new_node=new Node(val);
			new_node->next=temp->next;
			temp->next=new_node;
			
			new_node->prev=temp;
			new_node->next->prev=new_node; 
			return;
			
		}
		
		void deleteatstart(){
			if(head==NULL){
				return;
			}
			
	Node* temp=head;
	head=head->next;
	if(head==NULL){
		tail=NULL;
	}
	else{
		head->prev=NULL;
	}
	delete temp;
	return;
		}
	
};


int main(){
	Node* new_node=new Node(3);
	
	DoublyLL dll;
//	dll.insertathead(1);
//	dll.insertathead(2);
//	dll.insertathead(3);
//	dll.display();
	dll.insertatend(1);
	dll.display();
	dll.insertatend(2);
	dll.display();
	dll.insertatend(3);
	dll.display();
	
	dll.deleteatstart();
	dll.display();
	return 0;
}

//time compexity=O(1)
