#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template<class T>
void print(vector<T> v){
	for(T item: v)
		cout<<item;
	cout<<endl;
}

int main(){

	int size;
	vector<char> nodes;
	vector<vector<int>> adj_list;

	string fileName="text.txt";
	ifstream infile(fileName.c_str());
	char c=infile.get();
	size=c-'0';
	infile.get();
	while((c=infile.get())!='\n'){
		if(isalpha(c)){
			nodes.push_back(c);
		}
	}
	vector<int> weights;
	while((c=infile.get())!=-1){
		if(isalpha(c)){
			adj_list.push_back(weights);
			weights.clear();
		}
		if(isdigit(c))
			weights.push_back(c-'0');
	}
	cout<<"Size read: "<<size<<endl;
	print(nodes);
	for(vector<int> v: adj_list)
		print(v);
	infile.close();
}
