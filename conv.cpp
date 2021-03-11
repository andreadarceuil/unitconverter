/**@file: conv.cpp
   @author Andrea Darceuil
   @author a_darceuil@fanshaweonline.ca
   @date 2018-05-25
   @version 0.1
   @note Developed for Visual C++ 7.0/GCC 3.2
   @brief Implementation of mass converter that will convert between Imperial and Metric units
*/

#include <iostream>
#include <string>
#include<locale>
#include <regex>
#include<iomanip>

using namespace std;

//function prototype headers
bool restrictStringInput(string inputString);
void harmonizeCase(string& inputString);
bool matchUnit(string inputString, string exp);


int main()
{
	//Setting local Region settings
	locale here("");
	cout.imbue(here);
	

	//Program Welcome
	cout << "Mass converter, (c)2017-2018: Andrea d'Arceuil " << endl;
	
	//Step 1: Getting user input 
	cout << "Enter the mass: ";
	
	//Initializing variables to hold the input
	double unitWeight;
	string unit;
	//storing input in variables
	cin >> unitWeight;
	if (!cin.good())// i.e. input is invalid
	{
		cerr << " is an unknown unit and cannot be converted\n";
		return EXIT_FAILURE;
	}
	
	//using getline to get the string unit portion 
	getline(cin, unit);
	


	//Checking input to ensure user inputs the correct units for this program
		
	if (!restrictStringInput(unit))//checking user input for the units entered
	{
		cerr << unit << " is an unknown unit and cannot be converted" << endl;
		return EXIT_FAILURE;
	}
	else
	{
		harmonizeCase(unit); //removing whitespace and converting units to one uniform case: lowercase
		cout << unitWeight <<" "<<unit << " is ";
	}


	//UNIT CONVERSION SECTION

	//pennyweight dwt to grain gr
	if (matchUnit(unit, "dwt"))
	{

		double const DWT_TO_GR = 24;
		unitWeight *= DWT_TO_GR;
		cout << unitWeight<<" gr" << endl;
	}
	//gram g to ounce oz
	else if (matchUnit(unit, "g"))
	{
		double const G_TO_OZ = 0.035274;
		unitWeight *= G_TO_OZ;
		cout << unitWeight<<" oz" << endl;
	}
	//grain gr to pennyweight dwt
	else if (matchUnit(unit, "gr"))
	{
		double const GR_TO_DWT = 0.0416667;
		unitWeight *= GR_TO_DWT;
		cout << unitWeight <<" dwt" << endl;
	}
	//kilogram kg to pound lb
	else if (matchUnit(unit, "kg"))
	{
		double const KG_TO_LB = 2.20462;
		unitWeight *= KG_TO_LB;
		cout << unitWeight <<" lb" << endl;
	}
	//pound lb to kilogram kg
	else if (matchUnit(unit, "lb"))
	{
		double const LB_TO_KG = 0.453592;
		unitWeight *= LB_TO_KG;
		cout << unitWeight <<" kg" << endl;
	}
	//long tn to short tonne sh tn
	else if (matchUnit(unit, "long tn"))
	{
		double LONG_TN_TO_SH_TN = 1.12;
		unitWeight *= LONG_TN_TO_SH_TN;
		cout << unitWeight <<" sh tn" << endl;
	}
	//oz to g
	else if (matchUnit(unit, "oz"))
	{
		double const OZ_TO_G = 28.3495;
		unitWeight *= OZ_TO_G;		
		cout <<unitWeight << " g" << endl;
	}
	//sh tn to tonne
	else if (matchUnit(unit, "sh tn"))
	{
		double const SH_TN_TO_TONNE = 0.907185;
		unitWeight *= SH_TN_TO_TONNE;
		cout << unitWeight <<" tonne" << endl;
	}
	//tonne to sh tn
	else if (matchUnit(unit, "tonne"))
	{
		double const TONNE_TO_SH_TN = 1.10231;
		unitWeight *= TONNE_TO_SH_TN;
		cout << unitWeight << " sh tn" << endl;
	}
	

}

/*
/**@fn			void harmonizeCase(string& s)
   @brief		sanitizes user input to remove leading and trailing whitspace and address case iregularities
   @param var  [in] string
   @return     NOTHING!--void method  
   */
void harmonizeCase(string& inputString)  
{
	    //regex expression set to recognize the units of this program with any amount of whitespace before and after 
		regex unitExp(" *(dwt)( )*| *(gr)( )*| *(g)( )*| *(kg)( )*| *(lb)( )*| *(oz)( )*| *(tonne)( )*| *(sh)( )+(tn)( )*| *(long)( )+(tn)( )*", regex::icase);

		//using regex replace to replace whitespace from the string 
		inputString = regex_replace(inputString, unitExp, string("$1$3$5$7$9$11$13$15$16$17$19$20$21"));

		//using a for loop to iterate through every character in the string and convert each character to lowercase via tolower() function
		for (string::size_type i = 0; i < inputString.length(); ++i)
		{
		inputString[i] = tolower(inputString[i]);
		}

}

/**@fn			bool matchUnit(string s, string exp)
   @uses			regex_match to compare any two user-defined strings and it is NOT case sensitive
   @param var	[in] two strings 
   @returns		true if they match and false otherwise 
  */
bool matchUnit(string inputString, string exp)
{
	regex reg_icase(exp, regex::icase);
	if (regex_match(inputString, reg_icase))
	{
		
		return true;
	}
	else
		
		return false;
}

/**@fn		    bool restrictStringInput(string s)
   @brief		makes use of a regex match to restrict user input to any one of the acceptable 
			    units for the mass converter- it is case- insensitive and whitespace friendly
   @param var   [in] two strings for comparison
   @return		true only if the user inputs a valid string  
*/
bool restrictStringInput(string inputString)
{
	//only the strings defined in this expression will be acceptable input--
	regex reg_icase(" *dwt *| *(g)( )*| *(gr)( )*| *(kg)( )*| *lb *| *(long) +(tn)( )*| *(oz)( )*| *(sh) +(tn)( )*| *(tonne)( )*", regex::icase);

	if ((regex_match(inputString, reg_icase)))
	{
		return true;
	}
	else
		return false;
}





