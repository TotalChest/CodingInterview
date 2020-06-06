#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;

int main (){
	unordered_set<char> J;
    int c, count = 0;;
	while((c = getchar()) != '\n')
    	J.insert(c);

	string S;
    cin >> S;
    
    for(const char ch: S)
    	if(J.find(ch)!=J.end())
        	++count;
            
   	cout << count;
    return 0;
}