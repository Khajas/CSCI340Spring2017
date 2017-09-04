#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
const int HEAP_SIZE = 50;
const int SPACING=5;
const int E_PER_LINE=8;
void heapify(vector<int>& v, int heap_size, int r, bool (*compare)(int, int)){
	if(2*r > heap_size) return;	// If root's left child is greater than heap size then return
	int lh=2*r;			// Left child's index
	int rh=2*r+1;			// Right child's index
	int swap_idx=r;			// Let's the smallest(largest) element index be root or r 
	if(lh <= heap_size)			// If the index of left child is a valid index
		if(compare(v[lh], v[r]))	// and left child is smaller(greater) than the root
			swap_idx=lh;		// then update the smallest(greatest) imdex to be left child
	if(rh <= heap_size)				// If right child index is a valid index
		if(compare(v[rh], v[swap_idx]))		// and right child is smaller(greater) than the smallest(greatest) index so far
			swap_idx=rh;			// then update the smaller(greatest) index
	if(swap_idx != r){				// Now if this smallest(greatest) index is not the root
		int temp=v[r];				// then swap the smallest(greatest) index with the root
		v[r]=v[swap_idx];
		v[swap_idx]=temp;
	}						// Now move on to the next element
	heapify(v, heap_size, ++r, compare); 
}
void build_heap(vector<int>& v, int heap_size, bool(*compare)(int, int)){
	for(int i=heap_size/2;i>0;--i)
		heapify(v, heap_size, i, compare);
}
bool less_than(int e1, int e2){
	return e1 <= e2;
}
bool greater_than(int e1, int e2){
	return e1 >= e2;
}
void print_vector(vector<int>& v, int pos, int size){
        for(int i=pos,count=1;i<=size;++i, ++count){
                cout<<setw(SPACING)<<v[i];
                if(count%E_PER_LINE==0) cout<<endl;
        }
        cout<<endl;
}

int extract_heap(vector<int>& v, int& heap_size, bool(*compare)(int, int)){
	if(heap_size <=0 ) return -1;
        int old_root=v[1];
        v[1]=v[heap_size];
	v[heap_size]=old_root;
        heapify(v, --heap_size, 1, compare);
        return old_root;
}

void heap_sort(vector<int>& v, int heap_size, bool (*compare)(int, int)){
	if(heap_size<=1) return;
	build_heap(v, heap_size, compare);
	for(int i=heap_size;i>heap_size/2; --i)
		extract_heap(v,heap_size,compare);
	reverse(v.begin()+1, v.end());	
}
int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;//={-1,9,8,14};
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE);
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}
