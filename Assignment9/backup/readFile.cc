#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int size;
vector<char> nodes_list;
vector<vector<int>> adj_list;
using namespace std;
int main(){
	string fileName="text.txt";
	ifstream ifs;
        ifs.open(fileName.c_str(),ifstream::in);
        char c=ifs.get();
	size=c-'0';
	for(char node;getline();nodes_list.push_back(node));
        ifs.close();
}
