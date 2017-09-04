#include <iostream>
#include <iomanip>
#include <algorithm>
#include "assignment4.h"
using namespace std;

bool Stack::empty() const {
	return q1.empty() & q2.empty();
}

int Stack::size() const {
	return q1.size()+q2.size();	
}

int Stack::top() {
	if(q1.empty() & q2.empty()) return '\0';
	if(q2.empty())
		return q1.back();
	return q2.back();
}

void Stack::push(const int& val) {
	if(q2.empty())
		q1.push(val);
	else q2.push(val);
}

void Stack::pop() {
	if(q1.empty() & q2.empty()) return;
	if(q1.empty()){
		while(q2.size()>1){
			q1.push(q2.front());
			q2.pop();
		}
		q2.pop();
	}else{
		while(q1.size()>1){
                        q2.push(q1.front());
                        q1.pop();
                }
                q1.pop();
	}
}

int main() {
    Stack s;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            s.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            s.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << s.size() << setw(5) << s.top() << endl;
        cin >> op;
    }

    while ( !s.empty() )
        s.pop();
    cout << "End -- size of Stack is: " << s.size() << endl;

    return 0;
}
