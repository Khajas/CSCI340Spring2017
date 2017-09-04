#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"
#include <algorithm>
using namespace std;
// Private Function
vector<char> n_trv;
void graph::depth_first( int i){
	if(i>=size) return;
	list<int> edges=adj_list[i];
	char c_ch=labels[i];
	if(find(n_trv.begin(), n_trv.end(),c_ch)==n_trv.end()){
		cout<<c_ch<<' ';
		n_trv.push_back(c_ch);
	}
	int j=0;
	for(int i: edges){
		if(i){
			char ch=labels[j];
			if(find(n_trv.begin(), n_trv.end(),ch)==n_trv.end()){
				n_trv.push_back(ch);
				cout<<ch<<' ';
				depth_first(j);
			}
		}
		++j;
	}
}
// Public Functions
graph::graph(const char* filename){
        ifstream infile(filename);
        char c=infile.get();
        this->size=c-'0';
        infile.get();	// Ignore the newline after size
        while((c=infile.get())!='\n'){	// While it's a new line
                if(isalpha(c)){			// If the character read is an alphabet
                        labels.push_back(c);
                }
        }
        list<int> weights;
        while((c=infile.get())!=-1){
                if(isdigit(c)){
                        weights.push_back(c-'0');
		}
		else if(isalpha(c)){
			if(!weights.empty()){
                        	adj_list.push_back(weights);
                        	weights.clear();
			}
                }
        }
	adj_list.push_back(weights);
	infile.close();
}
graph::~graph(){
	adj_list.clear();
	labels.clear();
}
int graph::get_size()const{
	return this->size;
}
void graph::traverse(){
	n_trv.clear();
	cout<<"------- travere of graph ------"<<endl;
	for(unsigned i=0;i<labels.size();++i)
		depth_first(i);
	cout<<endl;
	char prev=n_trv[0];
	for(unsigned i=1;i<n_trv.size();++i){
		cout<<"("<<prev<<", "<<n_trv[i]<<")"<<' ';
		prev=n_trv[i];
	}
	cout<<endl<<"--------- end of traverse -------"<<endl;
}
void graph::print()const{
	cout<<"Number of vertices in the graph: "<<size<<endl<<endl;
	cout<<"-------- graph -------"<<endl;
	for(char ch: labels){
		cout<<ch<<": ";
		int idx=ch -'A';
		list<int> edges=adj_list.at(idx);
		int j=0;
		for(int i: edges){
			if(i)
				cout<<labels.at(j)<<", ";
			j++;
		}
		cout<<endl;
	}
	cout<<"------- end of graph ------\n"<<endl;
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
