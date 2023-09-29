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
int main(){
	Node* node1=new Node(1);
	cout<<node1->val<<endl;
	cout<<node1->next<<endl;
	return 0;
}
