#include<bits/stdc++.h>
using namespace std;

class Queue{
	private:
		int max_size = 100;
		int* mem = new int[max_size];
		int front_index,back_index,size;
		
		//Reallocates double the original memory size
		void resize(){
			max_size*=2;
			int* arr = new int[max_size];
			for(int i=0,x=front_index;i<size;i++,x++) arr[i] = mem[x];
			delete [] mem;
			mem = arr;
		}
		
	public:
		Queue(){
			front_index = 0;
			back_index = -1;
			size = 0;
		}
		
		// Checks and returns the "front" element in the queue
		// or
		// Checks and returns the element at the front_index
		int front(){
			try{
				if(size>0) return mem[front_index];
				else{
					throw 1;
				}
			}
			catch(int err){
				cout << "Queue is empty!\n";
				exit(0);
			}
		}
		
		// Adds the given element to the queue
		// or
		// Increments the back_index and updates the value of the array at that index
		void push(int val){
			if(size==max_size) resize();
			back_index++;
			size++;
			mem[back_index] = val;
		}
		
		// Removes and returns the front element in queue
		// or
		// Removes and returns the element at the front_index then increment it
		int pop(){
			try{
				if(size>0){
					front_index++;
					size--;
					return mem[front_index-1];
				}
				else throw(1);
			}
			catch(int err){
				cout << "Queue is empty!\n";
				exit(0);
			}
		}
		
		// Prints the elements in the queue
		void print(){
			for(int i=front_index;i<back_index;i++)cout << mem[i] << " ";
			cout << endl;
		}
	
};

int main(){
	Queue sample;
	for(int i=0;i<10;i++){
		sample.push(i);
	}
	sample.print();
	for(int i=0;i<3;i++){
		cout << sample.pop() << endl;
	}
	sample.print();
	cout << "end"; 
}
