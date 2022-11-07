#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include "road.h"


using namespace std;

int main()
{
	
	ifstream infile;
	ofstream outfile;
	
	infile.open("input.txt");
//	ofstream.open("";);
	
	int array[5]={1,7,9,4,5};
	for(int i=0; i<5;i++)
	{
		cout<<array[i]<<" "; 
	}
	
	
		infile.close("input.txt");
		//outfile.close();
		
	if(!infile0)
		{
			cout << ""Could NOT open Input File" << endl;
		}
		
	return 0;
	
	
}
