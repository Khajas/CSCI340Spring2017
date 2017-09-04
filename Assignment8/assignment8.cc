#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "assignment8.h"

using namespace std;

HT::HT( int size = 11 )
{
	hTable = new vector<Entry>(size);

	table_size = size;

	item_count = 0;
}

HT::~HT()
{
	delete  hTable;
}

bool HT::insert( const Entry& e )
{
	if( search( e.key ) != -1 )
	{
		cout << "duplicate key" << endl;
		return false;
	}

	if( item_count >= table_size )
	{
		cout << "Overflow" << endl;
		return false;
	}

	int hBucket = hashing( e.key );

	if( (*hTable)[hBucket].key == "+++" || (*hTable)[hBucket].key == "---" )
	{
		(*hTable)[hBucket] = e;

		item_count++;

		return true;
	}
	else
	{
		int lProbe = ((hBucket + 1) % table_size);

                while( (lProbe) != hBucket && ( (*hTable)[lProbe].key != "---" || (*hTable)[lProbe].key != "+++" ) )
                {
                        if( (*hTable)[lProbe].key == e.key )
			{
				(*hTable)[lProbe] = e;

                		item_count++;

                		return true;
			}
                        else
                                lProbe = ((lProbe + 1) % table_size);
                }

                return false;
	}
}

int HT::search( const std::string& key )
{
	int hBucket = hashing( key );

//	if( (*hTable)[hBucket].key == key )

	if( key.compare((*hTable)[hBucket].key))
		return hBucket;
	else
	{
		int lProbe = ((hBucket + 1) % table_size);

		while( (lProbe) != hBucket && (*hTable)[lProbe].key != "---" )
		{
			if( (*hTable)[lProbe].key == key )
				return lProbe;
			else
				lProbe = ((lProbe + 1) % table_size);
		}

		return -1;
	}
}

bool HT::remove( const std::string& s )
{
	int rm = search( s );

        if( rm == -1 )
                return false;
        else
        {
                (*hTable)[rm].key = "+++";

                item_count--;

                return true;
        }
}

void HT::print()
{
	for( int i = 0; i < table_size; i++ )
	{
		cout << "test" << endl;
	}
}

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

Entry* get_entry( const std::string& line )
{

	Entry* eTemp = new Entry(); 	//#### You must initialize entry using new
				// ## Else you can't assign variables
	char split_char = ':';
	std::istringstream split(line);
	std::vector<std::string> tokens;
	for( std::string each; std::getline(split, each, split_char); tokens.push_back(each));

	eTemp->key =tokens[1];
	eTemp->description =tokens[2];

	return eTemp;
}
/*
	Entry* eTemp = 0;

	string toParse = line;

	string delimiter = ":";

	size_t pos = 0;
	int i = 0;

	vector<string> token;

	while ((pos = toParse.find(delimiter)) != string::npos)
	{
		token[i] = toParse.substr(0, pos);
		toParse.erase(0, pos + delimiter.length());
		i++;
	}

	eTemp->key = token[1];
	eTemp->description = token[2];

	return eTemp;
}
*/

std::string get_key( const std::string& line )
{
	 char split_char = ':';

        std::istringstream split(line);
        std::vector<std::string> tokens;
        for( std::string each; std::getline(split, each, split_char); tokens.push_back(each));

	return tokens[1];
/*	string toParse = line;

        string delimiter = ":";

        size_t pos = 0;
        int i = 0;

        vector<string> token;

        while ((pos = toParse.find(delimiter)) != string::npos)
        {
                token[i] = toParse.substr(0, pos);
                toParse.erase(0, pos + delimiter.length());
                i++;
        }

	return token[1];
*/
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
