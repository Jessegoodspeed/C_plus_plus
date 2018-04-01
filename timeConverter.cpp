/*******************************************************************
 Author: Jesse Goodspeed
 Date: 02/12/2015
 Description: Time Converter
**********************************************************************/

/*This program takes a given 24-hour time notation and converts it into a 12-hour format, indicating if it is AM or PM. */

#include <iostream>
using namespace std;

//Function Declaration
void convert( int hour, int min );

int main()
{
    //this program utilizes four variables
    int hour, min;
    char option, colon = ':'; 
	
    /*Prompt user for input, convert input to new format, prompt user again to repeat */
    do{
        cout<<"Enter 24 hour time in the format HH:MM" << endl;
	cin>> hour >> colon >> min; 
	cout<< "Time in 12 hour format:"<< endl; 
	convert(hour, min); 
        cout<<"Enter Y or y to continue, anything else quits."<< endl;
	cin>> option;
	
	//Input test to determine if user wants to repeat converter
	if(option != 'y' && option != 'Y')
		break; 
          
    }while(option == 'y' || option == 'Y'); 
    
    return 0;
}
           
//Function Definition------------
void convert( int hour, int min){
	
    /* Change the 24 hour format to 12 hour format, print the changed result with the corresponding AM/PM designation.*/	
    if (hour == 00){
	hour = 00 + 12;
	if (min < 10){
	cout<< hour << ":" << 0 << min << " AM"<< endl;
	} else cout<< hour << ":" << min << " AM"<< endl;
	}
    else if (hour == 24){
	hour = 24 - 12;
	if (min < 10){
	cout<< hour << ":" << 0 << min << " AM"<< endl;
	} else cout<< hour << ":" << min << " AM"<< endl;
	}
    else if (hour <= 11 && hour != 00){
	if (min < 10){
	cout<< hour << ":" << 0 << min << " AM"<< endl;
	} else cout<< hour << ":" << min << " AM"<< endl;
	}
    else if (hour == 12){
    	if (min < 10){
	cout<< hour << ":" << 0 << min << " PM"<< endl;
	} else cout<< hour << ":" << min << " PM"<< endl;
	}
    else if (hour > 12){
	hour = hour - 12;
	if (min < 10){
	cout<< hour << ":" << 0 << min << " PM"<< endl;
	} else cout<< hour << ":" << min << " PM"<< endl;
	}      
}
