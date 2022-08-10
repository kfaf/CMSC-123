#include<bits/stdc++.h>
using namespace std;

class Circ_Queue{
	private:
		int max_size = 10;
		int* mem = new int[max_size];
		int front_index,back_index,size;
		
		// Reallocates double the original memory size
		// The extra memory is inserted between the back_index and front_index
		void resize(){
			max_size*=2;
			int* arr = new int[max_size];
			for(int i=0;i<=back_index;i++) arr[i] = mem[i];
			if(back_index<front_index){
				for(int i=max_size-1,x=size-1;x>=front_index;i--,x--) arr[i]=mem[x];
			}
			delete [] mem;
			mem = arr;
			front_index = max_size-(size-front_index);
		}
	
	public:
		Circ_Queue(){
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
		// if it is out of bounds, it loops back to 0
		void push(int val){
			if(size==max_size)resize();
			if(back_index==max_size-1) back_index=-1;
			back_index++;
			size++;
			mem[back_index] = val;
		}
		
		// Removes and returns the front element in queue
		// or
		// Removes and returns the element at the front_index then increment it
		// if it is out of bounds, it loops back to 0
		int pop(){
			try{
				if(size>0){
					int temp = mem[front_index];
					if(front_index==max_size-1)front_index=-1;
					front_index++;
					size--;
					return temp;
				}
				else throw(1);
			}
			catch(int err){
				cout << "Queue is empty!\n";
				exit(0);
			}
		}
		
		// Prints the elements in the array
		void print(){
			for(int i=0;i<max_size;i++)cout << mem[i] << " ";
			cout << endl;
		}
		
	
};

int main(){
	Circ_Queue sample;
	for(int i=0;i<10;i++) sample.push(i);
	sample.print();
	for(int i=0;i<5;i++) cout << sample.pop() << endl;
	for(int i=10;i<15;i++) sample.push(i);
	sample.print();
	for(int i=1;i<6;i++) sample.push(i);
	sample.print();
	for(int i=0;i<15;i++) cout << sample.pop() << endl;
	sample.print();
	cout << "end"; 
}
