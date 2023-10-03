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

void insertattail(Node* &head,int val){
	Node* new_node=new Node(val);
	
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
temp->next=new_node;

}

void insertatposition(Node* &head, int val,int pos){
	if(pos==0){
		insertathead(head,val);
		return;
	}
	Node* new_node=new Node(val);
	Node* temp=head;
	int current_pos=0;
	while(current_pos!=pos-1){
		temp=temp->next;
		current_pos++;
	}
	//temp is ponting to node at pos-1;
	new_node->next=temp->next;
	temp->next=new_node;
}

void updateatposition(Node* &head,int k, int val){
	Node* new_node=new Node(val);
	Node* temp=head;
	int cur_pos=0;
	while(cur_pos!=k){
		temp=temp->next;
		cur_pos++;
	}
	//Temp will be pointing to kth node
	temp->val=val;
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
insertattail(head,3);
display(head);
insertatposition(head,4,1);
display(head);
updateatposition(head,2,5);
display(head);
	return 0;
} 
