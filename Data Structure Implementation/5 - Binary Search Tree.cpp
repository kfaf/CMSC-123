#include<bits/stdc++.h>
using namespace std;

class BST{
	private:
		int max_size = 15;
		int* mem = new int[max_size];
		int height;
		
		// Reallocates additional memory for another height in tree
		void resize(){
			height++;
			int new_max_size = max_size+pow(2,height);
			
			int* arr = new int[new_max_size];
			for(int i=0;i<max_size;i++) arr[i] = mem[i];
			for(int i=max_size;i<new_max_size;i++)arr[i]=0;
			max_size = new_max_size;
			delete [] mem;
			mem = arr;
		}
		
	public:
		BST(){
			height = 3;
			//for(int i=0;i<max_size;i++) mem[i]=NULL;
			memset(mem,0,max_size*sizeof(int));
		}
		
		// Pushes val into the tree, following the rule that values lesser than the parent
		// goes to the left while values greater goes to the right until the value of the 
		// parent is NULL then places the val in that index
		void push(int val){
			int index = 0;
			while(true){
				while(index>max_size) resize();
				if(mem[index]==NULL){
					mem[index]=val;
					break;
				}
				
				if(val>mem[index])index = (index*2)+2;
				else index = (index*2)+1;
			}
		}
		
		// Searches the tree if val exists
		// It does this by taking advantage of the property of a binary tree
		// The algorithm is similar to the push() function
		bool search(int val){
			int index = 0;
			while(index<max_size || mem[index]!=NULL){
				if(mem[index]==val) return true;
				
				if(val>mem[index])index = (index*2)+2;
				else index = (index*2)+1;
			}
			return false;
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
	BST sample;
	sample.push(8);
	sample.push(10);
	sample.push(3);
	sample.push(1);
	sample.push(6);
	sample.push(14);
	sample.push(4);
	sample.push(7);
	sample.push(13);
	sample.push(15);
	sample.push(16);
	//---------------------------//
	int search_var = 8;
	if(sample.search(search_var))printf("BST contains %d\n",search_var);
	else printf("BST does not contain %d\n",search_var);
	sample.print();
	cout << "end";
}
