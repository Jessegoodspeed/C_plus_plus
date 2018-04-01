/*******************************************************************
 Author: Jesse Goodspeed
 Date: 02/27/2015
 Description: Denominations
**********************************************************************/

/*This program prompts a user to enter a dollar amount, and then calculates how many of each denomination is needed to equal the given dollar amount.*/

#include <iostream>
using namespace std;

int twenty = 0,
  five = 0,
  one = 0,
  fiftyC = 0,
  twentyFiveC = 0,
  tenC = 0,
  fiveC = 0,
  oneC = 0,
  amount = 0,
  denom,
  coin = 0,
  initAmount = 0,
  initCoin = 0;

char decimal = '.';

//Function Declarations:
//Pre-condition: Takes the remaining dollar/coin amount, denomination, denomination count, and initial given dollar/coin amount.
//Post-condition: Prints the count of the evaluated denomination, and saves the remaining dollar/coin amount, if any.
void DollarCount(int denom, int& amount, int denomCount, int initCoin, int initAmount);

//Pre-condition: Takes the given coin amount, value of coin denomination, count, and initial coin amount.
//Post-condition: Prints the count of the evaluated denomination, and remaining coin amount, if any.
void CoinCount(int denom, int& coin, int denomCount, int initCoin);

int main(){
  
  cout << "This program calculates how many bills/coins of each denomination are needed to equal an entered dollar amount." << endl;
  cout << "Use the following format: 00.00" << endl;
  cout << "(Examples: $1.45 would be entered as 1.45, $5 would be 5.00 and 8 cents would be 0.08)." << endl;
  cout << "Enter Amount: "; //user prompt
  cin >> initAmount >> decimal >> initCoin;

  cout << "You need "; 
  
  amount = initAmount; //initializes the amount variable
  coin = initCoin; //initializes the coin variable

  //A function call is made for each corresponding denomination, starting with the greatest value first
  DollarCount(20, amount, twenty, initCoin, initAmount);
  
  DollarCount(5, amount, five, initCoin, initAmount);
  
  DollarCount(1, amount, one, initCoin, initAmount);

  CoinCount(50, coin, fiftyC, initCoin);

  CoinCount(25, coin, twentyFiveC, initCoin);

  CoinCount(10, coin, tenC, initCoin);

  CoinCount(5, coin, fiveC, initCoin);

  CoinCount(1, coin, oneC, initCoin);

    return 0;
}
           
//Function Definitions:

/* This function takes given dollar amount,  counts how many bills of the single denomination are needed, and then prints the result.  Any remaining amount will be left for another consecutive function call. */
void DollarCount(int denom, int& amount, int denomCount, int initCoin, int initAmount){
  if ((initAmount == amount) && (amount%denom == 0) && (amount/denom > 1) && (initCoin == 0)){
    denomCount = amount/denom;
    cout << denomCount << " " << "$" << denom << " bills." << endl;
    amount = 0;
  } //If initial amount fits neatly in one denomination alone and needs multiple bills. 


  if ((initAmount == amount) && (amount%denom == 0) && (amount/denom == 1) && (initCoin == 0)){
    denomCount = amount/denom;
    cout << denomCount << " " << "$" << denom << " bill." << endl;
    amount = 0;
  } //If initial amount fits neatly in one denomination alone and only needs one bill. 


  if (amount%denom == 0){
    denomCount = amount/denom;
    amount = 0;
  }
  if (amount/denom > 0){
    denomCount = amount/denom;
    amount = amount%denom;
  }
  if ((denomCount == 1) && (amount == 0) && (initCoin == 0))
    cout << "and " << denomCount << " " << "$" << denom << " bill." << endl;
  else if (denomCount == 1)
    cout << denomCount << " " << "$" << denom << " bill, ";
  if ((denomCount > 1) && (amount == 0) && (initCoin == 0))
    cout << "and " << denomCount << " " << "$" << denom << " bills." << endl;
  else if (denomCount > 1)
    cout << denomCount << " " << "$" << denom << " bills, ";
} 

/* This function takes given coin amount, counts how many coins of the single denomination are needed,  and then prints the result.  Any remaining amount will be left for another consecutive function call. */
void CoinCount(int denom, int& coin, int denomCount, int initCoin){
  if ((initCoin == coin) && (coin%denom == 0) && (coin/denom > 1) && (initAmount == 0)){
    denomCount = coin/denom;
    cout << denomCount << " " << denom << 'c' << " coins." << endl;
    coin = 0;
  } //If initial coin amount fits neatly in one denomination alone and needs multiple coins. 

  if ((initCoin == coin) && (coin%denom == 0) && (coin/denom == 1) && (initAmount ==0)){
    denomCount = amount/denom;
    cout << denomCount << " " << denom << 'c' << " coin." << endl;
    coin = 0;
  } //If initial coin amount fits neatly in one denomination alone and only needs one coin.  


 if (coin%denom == 0){
    denomCount = coin/denom;
    coin = 0;
  }
  if (coin/denom > 0){
    denomCount = coin/denom;
    coin = coin%denom;
  }
  if ((denomCount == 1) && (coin == 0))
    cout << "and " << denomCount << " " << denom << 'c' << " coin." << endl;
  else if (denomCount == 1)
    cout << denomCount << " " << denom << 'c'  << " coin, ";
  
  if ((denomCount > 1) && (coin == 0))
    cout << "and " << denomCount << " " << denom << 'c' << " coins." << endl; 
  else if (denomCount > 1)
    cout << denomCount << " " << denom << 'c' << " coins, ";
}



