#include "assignment2.h"
const int DATA_SIZE = 200;
const int SEARCH_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;

void genRndNums( vector<int>& v, int seed ) {
	srand(seed);	//Seed for RNG of first vector.
	for(unsigned idx=0;idx<v.size();idx++){
		v[idx]=rand()%(HIGH-LOW+1)+LOW;
	}
}

int linearSearch( const vector<int>& inputVec, int x) {
	auto it=find(inputVec.begin(), inputVec.end(), x);
	if(it!=inputVec.end())
		return it-inputVec.begin();
	return -1;
}

int binarySearch( const vector<int>& inputVec, int x) {
	auto range=equal_range(inputVec.begin(), inputVec.end(),x);
	if(range.first==inputVec.end()) return -1;	// If the lower bound reaches end
	if(*(range.first)==x)				// If the element matches the lower bound
		return range.first-inputVec.begin();	// then return the disance
	return -1;	// If the element doesn't match the lower bound that means element is not founc, so return -1
}

int search( const vector<int>& inputVec, const vector<int>& searchVec,
            int (*p)( const vector<int>&, int) ){
	int foundNums=0;
	for(int num: searchVec){
		if(p(inputVec, num)!=-1) foundNums++;
	}
	return foundNums;
}

void sortVector (vector<int>& inputVec) {
	sort(inputVec.begin(), inputVec.end());
}

void printStat (int totalSucCnt, int vec_size) {
	cout<<"Successful searches: "<<right
                <<fixed<<setprecision(2)<<((totalSucCnt*100.0)*1.0/vec_size)<<"%"<<endl;
}

void print_vec( const vector<int>& vec ){
	for(unsigned idx=0; idx<vec.size(); idx++){
                cout<<setw(ITEM_W)<<vec[idx];
                if(((idx+1)%NO_ITEMS)==0) cout<<endl;
        }
        cout<<endl;
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}
