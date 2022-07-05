#include<bits/stdc++.h>
using namespace std;

class Node{
	public: 
		int val;
		Node* next;
		Node* prev;
	
		Node(){
			next = nullptr;
		}
		
		Node(int a, Node* b){
			val = a;
			next = b;
		}
		
		Node(int a){
			val = a;
			next = nullptr;
		}
};

class ArrayList{
	private:
		Node* head;
		Node* top;
		int size;
		
	public:
		ArrayList(){
			head = new Node();
			top = head;
			size = 0;
		}
		
		void push_back(int val){
			top->next = new Node(val);
			top = top->next;
			size++;
		}
		
		void print(){
			Node *temp =  head;
			temp = temp->next;
			while(temp){
				cout << temp->val << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		
		int& operator[](int index){
			try{
				if(index < size){
					Node *temp =  head;
					temp = temp->next;
					for(int i=0;i<index;i++) temp=temp->next;
					return temp->val;
				}
				else{
					throw 1;
				}
			}
			catch(...){
				cout << "Index out of range";
				exit(0);
			}
		}
};


int main(){
	ArrayList sample;
	sample.push_back(1);
	sample.push_back(2);
	sample.push_back(3);
	sample.print();
	cout << "\n" << sample[3];
	cout << "\nend";
}
