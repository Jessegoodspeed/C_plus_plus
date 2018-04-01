/*******************************************************************
 Author: Jesse Goodspeed
 Date: 02/20/2015
 Description: Simulation
**********************************************************************/

/*This program is a game simulation of a three-shooter gun duel that utilizes a pseudo-random number generator to determine the outcome.  Each of the three shooters has a different level of accuracy, and turn-by-turn, starting with the least proficient, they each attempt to take down the most talented of the others first. This duel is run 10000 times to acquire accurate statistics of the simulation. */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
using namespace std;

bool Aaron = true,
  Bob = true,
  Charlie = true;

int accuracy,
  score1 = 0,
  score2 = 0,
  score3 = 0;

double stat1, stat2, stat3;

//Function Declarations

//Duel function - simulates a single shooters shot depending on their level of accuracy
//Pre-condition: live shooter with two potential targets (remaining players) and shooters proficiency level
//Post-condition: depending on proficiency level, the random # generator will determine if a target was killed 
void duel(bool & shooter , bool & player1, bool &player2, int accuracy);



//RunDuels function - runs the duels function until one person remains alive.
//Pre-condition: Starting with Aaron, each player takes a turn aiming at one other remaining gunfighter.
//Post-condition: The last remaining gunfighter is determined the winner.
void runDuels(bool & Aaron, bool & Bob, bool & Charlie);

int main()
{
  //Does 10000 duels that are done until only one person remains alive.
  //This many times gives accurate statistics for the person remaining alive.
  for(int i=0;i<10000;i++){
    Aaron = Bob = Charlie =  true;
    runDuels(Aaron, Bob, Charlie);
  }

  //Calculates percent-wins and prints the final results
  stat1 = score1/static_cast<double>(100);
  stat2 = score2/static_cast<double>(100);
  stat3 = score3/static_cast<double>(100);
    
  cout <<"Aaron won " << score1 << " times! (" << stat1 << "%)" << endl;
  cout <<"Bob won " << score2 << " times! (" << stat2 << "%)" << endl;
  cout <<"Charlie won " << score3 << " times!(" << stat3 << "%)" << endl; 
    
    return 0;
}

//Function Definitions:

/*Duel function: Based on the shooters level of accuracy, the pseudo number generator will determine if he hit his target. The pseudo number generator used is mt19937, which is based on the Mersenne Twister algorithm and is seeded using a high resolution clock.  I chose this generator and seed value as it provides better statistical value and a stronger level of random number generation than the srand, rand  and time functions. */
void duel(bool & shooter, bool & player1, bool & player2, int accuracy){
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  mt19937 mt_rand(seed);
  int shot = mt_rand()% accuracy;
  if (shooter == true){ 
    if (shot == 0 && player2 == true)
      player2 = false;
    else if (shot == 0 && player2 == false && player1 == true)
      player1 = false;
  }
}

/*RunDuels function: the duel begins with three shooters, but only one leaves standing. Aaron starts first with 1/3 accuracy, and then Bob with 1/2 accuracy. And finally, Charlie the sharpest shooter with 1/1 accuracy. Whoever remains standing at the end, earns one point to their final score. */
void runDuels(bool & Aaron, bool & Bob, bool & Charlie){
  while((Aaron == true && Bob == true)||(Bob == true && Charlie == true)||(Aaron == true && Charlie == true)){
  if (Aaron == true)
    duel(Aaron, Bob, Charlie, 3);
  if (Bob == true)
    duel(Bob, Aaron, Charlie, 2);
  if (Charlie == true)
    duel(Charlie, Aaron, Bob, 1);
  }
  if(Aaron == true && Bob == false && Charlie == false)
    score1++;
  if(Aaron == false && Bob == true && Charlie == false)
    score2++;
  if(Aaron == false && Bob == false && Charlie == true)
    score3++;
}









