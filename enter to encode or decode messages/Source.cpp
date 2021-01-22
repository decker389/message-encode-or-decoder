/*
Program Name: enter to encode or decode message
Programmer: Chris Decker
Start Date: 11/18/2017
Purpose: to encode or decode messages by inputing a message and inputing by how much you want the message incoded or decoded
*/
#include <iostream> //includes the iostream file from the library
#include <time.h> //includes the time.h file from the library
#include <string> //includes the string file from the library
#include <cstring> //includes the cstring file from the library
using namespace std; //tells compiler that the proram will use standard naming practices
class codes //class called codes
{
private: // creates the private part of the class codes
	static const int notmax = 2000; //creates a static const integer called notmax set at 2000 
	string type, message,counted; //creates string variables called type, message, and counted
public: //public part of the class codes
	void messge() //function that doesn't return a value
	{
		cout << endl << "Please enter your message and end it with the ~ symbol" << endl; //prints message to user for them to input a message to be used
		char count [notmax+1]; //sets up an array of characters the array is the variablenotmax plus one in length
		cin.getline(count, notmax,'~'); //line for grabbing message from user, lets grabs the line up to the variable of notmax and teminates the input with the ~ key
		counted = count; //string counted is equal to variable count
	}
	void encode() //function encode returns no values
	{
		int coding; //creates integer called coding
		cout << "How much do you want to encode your message by?" << endl; //message for user asking how they want to encode their message
		cin >> coding; //gets user input for the counted variable
		int message = counted.length(); //sets integer message to the length of counted variable
		cout << "This is your code:" << endl; //prints message for user telling them the code
		for (int encode = 0; encode < message; encode++) //for loop using integer encode set set at value of 0 contiues till encode is equal to message and increases encode each time the loop completes
		{
			for (int times = 0; times < coding; times++) //for loop using integer times set at 0, contiues till times is equal to coding, increases times each time through
			{
				if (isalpha(counted[encode])) //if the location in array counted at location encode is a letter of the alphabet do this
				{
					if (counted[encode] == 'z') //if array counted location encode is a z make it
						counted[encode] = 'a'; //make the array counted location encode an a
					else if (counted[encode] == 'Z') //if array counted location encode is a Z  
						counted[encode] = 'A'; //make array counted location encode an A
					else  //if none of the above is true
						counted[encode]++; //increase the array counted location encode by 1
				}
			}
		}
		cout << counted; //print out the variable counted (this is the encoded message)
	}
	void decode() //function decode has does not return a value
	{
		int uncoding, truemessage; //creates integer variables by the name of uncoding and truemessage
		cout << "By how much was your message encoded?" << endl; //prints line to user asking how much their message was encoded by
		cin >> uncoding; //asks user for input for variable uncoding
		truemessage = counted.length(); //sets truemeaage variable to the value of the length of variable counted
		cout << "This is the original message you were trying to get:" << endl; //prints line to user telling them they are about to get the unscrampled message
		for (int decode = 0; decode < truemessage; decode++) //for loop creates int decode and sets it to 0, contiues as long as decode is less than truemessage, increases decode each run through
		{
			for (int rounds = 0; rounds < uncoding; rounds++) //for loop creates integer rounds set to 0, contiues till rounds equals uncoding, incriments rounds by one each time through the loop
			{
				if (isalpha(counted[decode])) // asks if the current location in counted array is an alphabetic character
				{
					if (counted[decode] == 'a') // asks if the current location in counted is an a
						counted[decode] = 'z'; //sets the current location in counted to a z
					else if (counted[decode] == 'A') //if the current location in counted is not an a is it an A
						counted[decode] = 'Z'; //sets the current location in countedto Z
					else // if none of the above is true
						counted[decode]--; //decriment the value of the current location by 1 this should change a letter c to a b
				}
			}
		}
		cout << counted; //prints out counted variable to user
	}
	void doloop()
	{
		do // creates do loop
	{
	cout << "tell me weather you want to encode, decode, or quit: "; //prints message to user telling them their options for the program
	cin >> type; //asks the user for input for the variable type
	if (type != "encode" & type != "decode" & type != "quit") //while loop that goes untill type is equal to one of the three encode, decode or quit
	{
		cout << "You did not answer the question correctly, try again!"; // tells user that they inputed the wrong option and  they need to try again
		cin >> type; // asks foruser input for variable type
	} 
	if (type == "quit") //if variable type is equal to quit
	{
		system("cls"); //clear screen
		cout << "You choose to quit the program, thank you for using this program I hope you enjoyed!" << endl; //good bye message
		system("pause"); //pauses program waiting for any input
		exit(0); //exits program with error code 0 (natural termination, no proplems)
	}
	else if (type == "encode") //if variable type is equal to encode
	{
		messge(); //calls message function
		encode();// calls encode fucntion
	}
	else if (type == "decode") // if variable type is equal to encode
	{
		messge(); //calls message function
		decode(); //calls decode function 
	}
	cout << endl << "You can go again just let us know." << endl; // prints out line letting user know they can run through another message if they want
	}
	while (type != "quit"); //contiues do loop while type variable is not equal to quit
}
};
/*
function name: main
parameters: none
Purpose: to run the main part of the program and to call the other functions in the program
return value: integer, however this main function does not return a value to anything
*/
int main()
{
	cout << "Today we will encode or decode a message" << endl; //prints message to user telling them the use for the program
	codes message; //creates an instance of the class codes called message
	message.doloop(); //calls the doloop function in message instance of codes class
}