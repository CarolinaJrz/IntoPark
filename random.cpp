#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

int random(int from, int to){
    return rand() % (to - from + 1) + from;
}




int main(){
	
	int num_from, num_to;
    srand(time(0));
    
    cout << "Enter minimum" << "\n";
    cin >> num_from;
    cout << "Enter maximum" << "\n";
    cin >> num_to;
    cout << random(num_from,num_to) << "\n";
     

    return 0;
}
