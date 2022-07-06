#include<bits/stdc++.h>
using namespace std;

//Node class to be used in the arraylist
class Node{
	public: 
		int val;
		Node* next;
		Node* prev;
	
		Node(){
			next = nullptr;
			prev = nullptr;
		}
		
		Node(int a){
			val = a;
			next = nullptr;
			prev = nullptr;
		}
};

class ArrayList{
	// head is for the starting node of the arraylist
	// top is the ending node of the arraylist
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
		
		// creates new node with the given val and updates the "top" of the arraylist
		void push_back(int val){
			Node* temp = top;
			top->next = new Node(val);
			top = top->next;
			top->prev = temp;
			size++;
		}
		
		// removes the "top" node and retracts to the previous node pointing towards it
		void pop_back(){
			try{
				if(size>0){
					top = top->prev;
					delete top->next;
					top->next = nullptr;
					size--;
				}
				else throw 1;
			}
			catch(...){
				cout << "Arraylist is empty!";
				exit(0);
			}
		}
		
		// overladed operator for accessing elements in the arraylist by index
		int& operator[](int index){
			try{
				if((index>=0) && (index<size)){
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
				cout << "Index out of range!";
				exit(0);
			}
		}
		
		// prints the contents of the arraylist
		void print(){
			Node *temp =  head;
			temp = temp->next;
			while(temp){
				cout << temp->val << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};


int main(){
	ArrayList sample;
	sample.push_back(1);
	sample.push_back(2);
	sample.push_back(3);
	sample.push_back(4);
	sample.push_back(7);
	sample.print();
	sample.pop_back();
	sample.pop_back();
	sample.print();
	cout << sample[0] << endl;
	cout << "end";
}
