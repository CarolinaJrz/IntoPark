#include <iostream>
#include <iomanip>
#include <string>



void getInput(int day[], double rainfall[], int temps[][NUM_TEMPS], char condition[], ifstream& infile)
{
    // outer for loop controlling rows
    
    int row;
    int col;
    // input day[row]
	
   for(row = 0; row < NUM_BUILDINGS; row++)
   		{
   			infile >> day[row];
   			infile >> rainfall[row];
   		for(col = 0; col < NUM_LOTS; col++)
   			
   				infile >> temps[row][col];
		 	  
		   infile >> condition[row];
	   }
	

	
	
    // input rainfall[row]
 
       // inner loop controlling columns for temps array
       // input temps[row][col]
       // end of inner loop
    // input condition[row]
    // end of outer loop
    
    
}


void calcTempSumAverage(int temps[][NUM_TEMPS], double tempAverage[], int tempSum[])
{
    // this function is similar to calcRowSumAverage in the example program
		 int row, col;
		     
		     for(row=0;row<NUM_BUILDINGS;row++)
		     {
		         tempSum[row] = 0;
		         
		         for(col=0;col<NUM_LOTS;col++)
		              tempSum[row] = tempSum[row] + temps[row][col];
		              
		         tempAverage[row] = double(tempSum[row]) / double(NUM_TEMPS);
		                
		     }  
}

void findTempHighLow(int temps[][NUM_TEMPS], int tempHigh[], int tempLow[])
{
    // this is very similar to findRowHighLow in the example program
    int row, col;
    
     for(row=0;row<NUM_BUILDINGS;row++)
     {
         tempHigh[row] = temps[row][0];
         tempLow[row] = temps[row][0];
         
         for(col=1;col<NUM_BUILDINGS;col++)
         {
             if(temps[row][col] > tempHigh[row])
                 tempHigh[row] = temps[row][col];
                 
             if(temps[row][col] < tempLow[row])
                 tempLow[row] = temps[row][col];
                 
         }  // end of inner loop        
                 
     }   // end of outer loop        
    

}

void findOverallTempStuff(int temps[][NUM_BUILDINGS], int tempHigh[], int tempLow[],
                              double& overallTempAverage, int& overallTempSum,
                              int& overallTempHigh, int& overallTempLow)
{
     // this is similar to findOverallStuff in the example program
      int row, col;
    double indexima;
    overallTempAverage = 0;
    overallTempSum = 0;
    overallTempHigh = temps[0][0];
    overallTempLow = temps[0][0];
    
     for(row=0;row<NUM_BUILDINGS;row++)
     {
         for(col=0;col<NUM_BUILDINGS;col++) 
         {
             overallTempSum = overallTempSum + temps[row][col];
            
             if(temps[row][col] > overallTempHigh)
                overallTempHigh = temps[row][col];
                
             if(temps[row][col] < overallTempLow)
                overallTempLow = temps[row][col];
          }
          indexima = overallTempSum;				// I made up a double here so my average would reflect what my calculator said it should have been. 
          overallTempAverage = indexima / 42;
          //overallTempAverage = overallTempSum / (NUM_TEMPS * NUM_DAYS);
          
 }
 			
}

void calcRainfallSum(double rainfall[], double& rainfallSum)
{
    // this function should add up the values in the rainfall array (One dimensional array sum)
    
    		rainfallSum = 0;
    	for (int index = 0; index < NUM_DAYS; index++)
    	{
    		rainfallSum = rainfallSum + rainfall[index];
    		
		}
}

void outputResults(int day[], double rainfall[], double tempAverage[], int tempHigh[], int tempLow[], char condition[], 
double overallRainfallSum, double overallTempAverage, int overallTempHigh, int overallTempLow, ofstream& outfile ) // you will send in everything you need to output the results
{
	outfile << fixed << showpoint;
	
   // output labels
   
   int row;
   	outfile << "Day: " << setw(20) << "Rainfall: " << setw(20) << "Average: " 
	   << setw(14) << "High: " << setw(13) << "Low: " << setw(13) << "Condition:" << endl;
   	outfile << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
   	
   // loop that goes through 7 times (NUM_DAYS)
   		for (int index = 0; index < NUM_DAYS; index++)
   		{
   			outfile << left << setw(10);
   			
   			switch (day[index])
   			{
   				case 1: 
   					outfile << "Sunday";
   					break;
   				case 2:
   					outfile << "Monday";
   					break;
   				case 3: 
   					outfile << "Tuesday";
   					break;
   				case 4:
   					outfile << "Wednesday";
   					break;
   				case 5:
   					outfile << "Thursday";
   					break;
   				case 6:
   					outfile << "Friday";
   					break;
   				case 7:
   					outfile << "Saturday";
   					break;
   			}
   			
		outfile << right;
		outfile << setprecision(1);	   		
   		outfile << setw(13) << rainfall[index];
   		outfile << setw(20) << tempAverage[index];
   		outfile << setw(14) << tempHigh[index];
   		outfile << setw(13) << tempLow[index];
   		outfile << setw(14);
   		switch (condition[index])
   		{
   			case 'W':
   				outfile << "Windy";
   				break;
   			case 'S':
   				outfile << "Sunny";
   				break;
   			case 'R':
   				outfile << "Rainy";
   				break;
   			case 'C':
   				outfile << "Cloudy";
   				break;
   			}
   			
   			outfile << endl;
   			
		   
   // switch statement for day name    switch(day[row])
   // output rainfall[row]
   // output tempAverage[row]
   // output tempHigh[row]
   // output tempLow[row]
   // switch statement to output condition word   switch(condition[row])
		}
   // end of loop
   	outfile << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
   	
   	outfile <<  "Overall" << setw(16) << overallRainfallSum <<  setw(20) << overallTempAverage << 
	    setw(14) << overallTempHigh <<  setw(13) << overallTempLow << endl;
   // output dotted line
   // output overall things

}
