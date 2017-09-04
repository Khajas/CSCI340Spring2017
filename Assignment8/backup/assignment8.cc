#include "assignment8.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::ifstream;
using std::ios;
using std::smatch;
using std::regex;
using std::setw;
const int KEY_WIDTH=3;
//Global Functions:
Entry* get_entry(const string& line){
	regex pattern("[A-Z]:([\\w]+):([\\w]+)");
        smatch sm;
        regex_match(line,sm,pattern);
	Entry* e= new Entry();
	if(sm.size()!=3){
		delete e;
		e=NULL;
	}
	else
		e->key=sm[1]; e->description=sm[2];
	return e;
}

string get_key(const string& line){
	regex pattern("[A-Z]:([\\w]+)");
        smatch sm;
        regex_match(line,sm,pattern);
        if(sm.size()!=2)
                return "";
        return sm[1];
}

// Constructor
HT::HT(int s=11){
	this->table_size=s;
	this->hTable=new std::vector<Entry>(s);
        this->item_count=0;
}
// Public methods:
HT::~HT(){
	this->table_size=0;
	this->item_count=0;
	hTable->clear();
	delete hTable;
	hTable=NULL;
}
bool HT::insert(const Entry& e){
	if(table_size==item_count)
		return false;
	int pos=hashing(e.key);
	if(e.key==(*hTable).at(pos).key)
		return false;
	int i=pos;
	do{
		if(i==table_size) i=0;
		if(((*hTable).at(i).key=="---")||((*hTable).at(i).key=="+++")){
			hTable->at(i)=e;
			break;
		}
		++i;
	}while(i!=pos);
	this->item_count++;
	return true;
}
int HT::search(const std::string& str){
	int pos=this->hashing(str);
	Entry e=hTable->at(pos);
	if(e.key=="---")	return -1;
	// Key is stored at some other location, due to probing
	int i=pos;
	do{
		if(i==table_size) i=0;
		if((*hTable).at(i).key==str)
			return i;
		++i;
	}while(i!=pos);
	return -1;
}
bool HT::remove(const std::string& str){
	int pos=search(str);
	if(pos==-1) return false;
	Entry* e=&(hTable->at(pos));
	e->key="+++";
	e->description="";
	this->item_count--;
	return true;
}
void HT::print(){
	cout<<endl<<"----Hash Table-----"<<endl;
	for(unsigned i=0;i<hTable->size();++i)
		if(((hTable->at(i)).key!="---") & ((hTable->at(i)).key!="+++"))
			cout<<setw(KEY_WIDTH)<<i<<": "<<(*hTable).at(i).key<<' '<<
				(*hTable).at(i).description<<endl;
	cout<<"-------------------"<<endl<<endl;
}
// Private Methods:
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}
