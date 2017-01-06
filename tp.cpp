/*********************************************************
 * File name : tp.cpp
 * Author    : Michael Chu
 * Date      : 2/1/2015
 * Purpose   : Simulates the toilet-paper problem
 * Notes     : None
 *********************************************************/

#include <iostream>   // Basic I/O => cin, cout, etc.
#include <cstdlib>    // Other helpful functions => rand(), RANDMAX
#include <ctime>     
#include <iomanip>
using namespace std;

// Prototype/declaration of a function that returns a
// uniform random number between [0,1]
double rand_uniform();

// Prototype/declaration of a function that will perform a single
// simulation of two rolls of paper and users
// Returns the number of squares left on the non-empty roll
int single_roll_sim(int N, double p);

int main(int argc, char *argv[])
{
	
	const int num_sims = 100000;  // number of trials for our simulation

	int N;                // initial number of squares on each roll

  	double p;             // probability of a big-chooser
	
  	double total_squares = 0; // for each trial we'll keeping a running sum
        		  	  // of the squares left on the non-empty roll

	double avg = 0; //the average
	
	
  	// Do some error checking to make sure the user
  	// entered the correct number of arguments to the program
	
  	if(argc < 3)
	{
    	cout << "Usage: " << argv[0] << " N p" << endl;
    	cout << "\tN = number of squares on each roll to start" << endl;
    	cout << "\tp = probability of a big-chooser" << endl;
    	return 1;
  	}
  
 	N = atoi(argv[1]);   // convert the argument to an integer
 	p = atof(argv[2]);   // convert the argument to a floating point

  	// Add your code here
	srand (time(NULL));	//Seeded time to generate random values
	
	for(int i = 0; i <= num_sims; i++)
	{
		total_squares += single_roll_sim(N, p);	//runs the single_roll_simulation as many as num_sims times
	}
	
	avg = total_squares/num_sims;	
	
	cout << "Average number of squares left for N=" << N << ", p=" << p <<" is " << setprecision(5)<< avg <<endl;

 	return 0;
}

// return the number of squares on the non-empty roll
int single_roll_sim(int N, double p)
{
	int N1 = N;	//N1 = 1st roll
	int N2 = N;	//N2 = 2nd roll
	
	while(N1 > 0 && N2 > 0)	//loop that has the TP square decrementation
	{
		double patron = rand_uniform();		//calls the rand_uniform function to get random numbers

		if (patron > p)	//patron > p means little roll
		{
			if (N1 > N2)			//if N1 > N2, N1 is big roll
				N2--;
			else if (N1 < N2)		//N1 < N2, N@ 2 is big roll
				N1--;
			else				//if N1 = N2, then just decrement N1 (no diff)
				N1--;
		}
		else	//patron <= p means big roll
		{
			if (N1 > N2)
				N1--;
			else if (N1 < N2)
				N2--;
			else
				N1--;
		}
	}	

	if (N1 > 0)	//N1 > 0 means it's the remaining roll
	{
		return N1;
	}
	else		//if N1 <= 0, N2 is only one left as it's the only one to break the loop
	{
		return N2;
	}		

}

// returns a uniformly-distributed number in the range [0,1] works fine
double rand_uniform()
{
	double patron = ((double)rand()/(RAND_MAX));
	return patron;
}
