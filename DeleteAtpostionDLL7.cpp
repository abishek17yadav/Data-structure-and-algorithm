//time compexity=O(k) for worst o(n)
// Deletion at any position dll

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
		
	void deleteatend(){
		if(head==NULL){
			return;
		}
		Node* temp=tail;
		tail=tail->prev;
		if(tail==NULL){
			head=NULL;
		}
		else{
			tail->next=NULL;
		}
		delete temp;
		return;
	}
	
	void deleteatpostion(int k){
		//assuming k is less than or equal to length of dll;
		Node* temp=head;
		int counter=1;
		while(counter < k){
			temp=temp->next;
			counter++;
		}
		//now temp is pointing to node at kth pos
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
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
	dll.insertatend(4);
	dll.display();
//	
//	dll.deleteatstart();
//	dll.display();
//	
//	dll.deleteatend();
//	dll.display(); 
	
	dll.deleteatpostion(3);
	dll.display();
	return 0;
}

//time compexity=O(k) for worst o(n);
