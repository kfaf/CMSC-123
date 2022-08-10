#include<bits/stdc++.h>
using namespace std;

class Stack{
	private:
		int max_size = 5;
		int* mem = new int[max_size];
		int top_index,size;
		
		//Reallocates double the original memory size
		void resize(){
			max_size*=2;
			int* arr = new int[max_size];
			for(int i=0;i<size;i++) arr[i] = mem[i];
			delete [] mem;
			mem = arr;
		}
		
	public:
		Stack(){
			top_index = -1;
			size = 0;
		}
		
		// Checks and returns the "top" element in the stack
		// or
		// Checks and returns the last element in the array
		int top(){
			try{
				if(size>0) return mem[top_index];
				else{
					throw 1;
				}
			}
			catch(...){
				cout << "Stack is empty!\n";
				exit(0);
			}
		}
		
		// Adds the given element to the "top" of the stack
		// or
		// Increments the top_index and updates the value of the array at that index
		void push(int val){
			if(size==max_size) resize();
			top_index++;
			size++;
			mem[top_index] = val;
		}
		
		// Removes and returns the "top" element in stack
		// or
		// Removes and returns the last element in the array
		int pop(){
			try{
				if(size>0){
					top_index--;
					size--;
					return mem[top_index+1];
				}
				else throw(1);
			}
			catch(...){
				cout << "Stack is empty!\n";
				exit(0);
			}
		}
		
		// Prints the elements in the stack
		void print(){
			for(int i=0;i<size;i++)cout << mem[i] << " ";
			cout << endl;
		}
};

int main(){
	Stack sample;
	for(int i=1;i<10;i++){
		sample.push(i);
	}
	sample.print();
	cout << sample.top() << endl;
	sample.pop();
	cout << sample.top() << endl;
	sample.pop();
	sample.print();
	cout << "end";
}
