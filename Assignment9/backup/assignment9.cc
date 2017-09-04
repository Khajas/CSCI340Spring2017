#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"
using namespace std;
// int size;
// std::vector< std::list<int> > adj_list;
// std::vector< char > labels;
// Private Function
void graph::depth_first( int ){
	
}
// Public Functions
graph::graph(const char* filename){
	ifstream inFile;
	inFile.open(fileName.c_str(),ifstream::in);
	string line;
	ifs.getline(line);
	while(line){
		cout<<line;
		inFile.getline(line,'\n');
		
	}
	inFile.close();
}
graph~graph(){

}
int graph::get_size()const{

}
void graph::traverse(){

}
void graph::print()const{

}

#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }
    
    graph g(argv[1]);

    g.print();
    
    g.traverse();

    return 0;
}

#endif
