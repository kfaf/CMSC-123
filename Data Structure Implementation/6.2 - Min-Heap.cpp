#include<bits/stdc++.h>
using namespace std;

class Min_Heap{
	private:
		int max_size = 10;
		int* mem = new int[max_size];
		int size;
		
		//Reallocates double the original memory size
		void resize(){
			max_size*=2;
			int* arr = new int[max_size];
			for(int i=0;i<size;i++) arr[i] = mem[i];
			for(int i=size;i<max_size;i++) arr[i] = NULL;
			delete [] mem;
			mem = arr;
		}
		
	public:
		Min_Heap(){
			size = 0;
			for(int i=0;i<max_size;i++) mem[i]=NULL;
			//memset(mem,0,max_size*sizeof(int));
		}
		
		// Adds val to the back of the array and rearranges its order so it does
		// not violate the rule that the parent should be the least among
		// its two children
		void push(int val){
			mem[size] = val;
			int index = size;
			int parent = (index-1)/2;
			size++;
			if(size>=max_size)resize();
			
			while(parent>=0 && mem[parent]>mem[index]){
				swap(mem[parent],mem[index]);
				index = parent;
				parent = (index-1)/2;
			}
		}
		
		// Removes and returns the first element in the array then
		// it swaps values between parent and child if child<parent
		// until all affected "nodes" are fixed
		int pop(){
			int ans = mem[0];
			swap(mem[0],mem[size-1]);
			mem[size-1] = NULL;
			int index = 0;
			
			while(true){
				int left = (2*index)+1;
				int right = (2*index)+2;
				int comp = index;
				if(left<size && mem[left]!=NULL && mem[left]<mem[comp]) comp = left;
				if(right<size && mem[right]!=NULL && mem[right]<mem[comp]) comp = right;
				if(comp==index)break;
				
				swap(mem[index],mem[comp]);
				index = comp; 
			}
			size--;
			return ans;
		}
		
		// Prints the elements in the array
		void print(){
			for(int i=0;i<max_size;i++){
				if(mem[i]==NULL) cout << "Null ";
				else cout << mem[i] << " ";
			}
			cout << endl;
		}
	
};

int main(){
	Min_Heap sample;
	sample.push(5);
	sample.push(3);
	sample.push(11);
	sample.push(1);
	sample.push(6);
	sample.push(21);
	//------------------//
	sample.print();
	cout << sample.pop() << endl;
	cout << sample.pop() << endl;
	cout << sample.pop() << endl;
	sample.print();
	cout << "end";
}
