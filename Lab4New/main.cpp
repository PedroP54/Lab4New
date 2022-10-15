#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

string Temperature = "inTemp.dat";
int main()
{ // BEGINNING MAIN

	// Beginning Header 
	cout << "Temperatures for 24 hours:" << endl;
	cout << setw(8) << "-30";
	cout << setw(8) << "0";
	cout << setw(10) << "30";
	cout << setw(10) << "60";
	cout << setw(10) << "90";
	cout << setw(10) << "120" << endl;
	// End Header


  // Variable Declaration Zone 
	int Temp1, StarsCount, Space;


	ifstream infile; // READ THE FILE
	infile.open(Temperature);
	if (!infile) { // IF1 - prints a comment if the program does not read the file 
		cout << "cant read  the file!";
	} // END READ FILE


	infile >> Temp1;


	while (infile)
	{

		cout << setw(5) << Temp1;

		if (Temp1 < 0 && Temp1 > -30) { //IF2 - negative temps


			StarsCount = 0;
			Temp1 = Temp1 * -1;


			if (Temp1 % 3 == 2) {// Is adding one star if the remainder is equal to 2 

				StarsCount = StarsCount + 1;

			}


			Temp1 = Temp1 - (Temp1 % 3); // Makes the temperature exactly divisible by 3
			StarsCount = StarsCount + (Temp1 / 3); //The total amount of stars that has to be printed 

			for (int a = 0; a < (10 - StarsCount); a++) {//Print Spaces

				cout << setw(1) << " ";
			}



			for (int i = 0; i < StarsCount; i++) {//Printing Stars 

				cout << setw(1) << "*";
			}


			cout << setw(1) << "|";


			Temp1 = Temp1 * -1; //Returns the temperature to negative, so does not enters the positive temps condition 
			cout << endl;

		}//IF2 - end of negative temps 








		if (0 < Temp1 && Temp1 <= 120) { //IF3 - Positive Values 

			cout << setw(11) << "|"; //Printing starting point, not need for printing spaces because setw does the job

			StarsCount = Temp1 / 3;


			if (Temp1 % 3 == 2) {//Is adding one star if the remainder is equal to 2

				StarsCount = StarsCount + 1;
			}


			for (int i = 0; i < StarsCount; i++) {//Printing Stars

				cout << "*";

			}
			cout << endl;


		}
		else if (Temp1 == 0) {//Is going to print a start instead of a line

			cout << setw(11) << "*" << endl;

		}
		else if (Temp1 > 120 || Temp1 < -30) {//Declares that is goint to read values between this range
			cout << "    " << "Temperature out of range" << endl;
		}
		infile >> Temp1;
	} // END - while


} // END MAIN 
