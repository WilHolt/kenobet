/**
 * @file kenobet.h
 * @brief this is the include file of project
 * 
*/
#ifndef _KENOBET_H_
#define _KENOBET_H_

#include <iostream>
#include <vector>
#include <random>
#include <string>     // std::string, std::to_string
#include <chrono>// sleep_for, sleep_until
#include <thread>// nanoseconds, system_clock, seconds
#include <ctime> //time
#include <cstdlib> //rand 

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

using number_type = unsigned short int ; // <! data type for a keno hit.
 using cash_type = float ; // <! Defines the wage type in this application .
 using set_of_numbers_type = std::vector<number_type>;

 class KenoBet{
 private:
	 cash_type m_wage;
	 std::vector<number_type> bet;
	 std::vector<std::vector<cash_type>> payout;
	 std::vector<number_type> turn;
	 number_type round_qtd;
	 number_type round_count;

 public:
 //! Creates an empty Keno bet.
 KenoBet():m_wage (0), round_count(1){ 
	 payout = { { 0, 3},
{ 0, 1, 9},
{0, 1, 2, 16},
{ 0, 0.5, 2, 6, 12},
{ 0, 0.5, 1, 3, 15, 50},
{ 0, 0.5, 1, 2, 3 ,30 ,75},
{ 0 ,0.5, 0.5, 1, 6, 12, 36, 100},
{ 0 ,0.5, 0.5, 1, 3, 6, 19 , 90, 720},
{ 0 ,0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
{ 0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
{ 0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
{ 0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000 ,4000},
{ 0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000 ,6000},
{ 0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
{ 0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};
	std::vector<cash_type> aux;
	for(unsigned int i = 0; i < 15; i++){
		//aux = payout[i];
		//for(unsigned int j=0;j<aux.size(); j++){
		//	std::cout << payout[i][j]<< " ";
		//}
		//std::cout<<std::endl;
	}
	for(unsigned int k = 0; k<20 ; k++){
		turn.push_back(0);
	}

 };

 /** 
  * @brief Adds a number to the spots only if the number is not already there .
  * @param spot_ The number we wish to include in the bet.
  * @return T if number chosen is successfully inserted ; F otherwise . */
 bool add_number( number_type spot_ );

 /**
  * @brief Sets the amount of money the player is betting .
  * @return True if we have a wage above zero ; false otherwise .
  * @param wage_ The wage .  
 */
bool set_wage( cash_type wage_ );

 /**
  * @brief Sets the quantity of round the player will play .
  *  @param round_ The round .
  *  @return True if we have a wage above zero ; false otherwise .
  */
bool set_rounds( number_type rounds_ );

 //! Resets a bet to an empty state .
void reset( void );

 /*! Retrieves the player ’s wage on this bet.
 @return The wage value . */
cash_type get_wage(void) const ;


 /** @brief Show Vector of Bets
 @return void . */
void show_bets();

 /** @brief Show Payout Table
  *  @return void . */
void show_payout();
 /** 
  * @brief Returns to the current number of spots in the player ’s bet.
  * @return Number of spots present in the bet. */
size_t size (void) const;

 /** @brief 
  * Generate 20 random numbers every round
  * @return void . */
void roll_turn();

 /** @brief
  *  Check if the player have hit.
  *  @return True if we have a hit ; false otherwise . */
 bool check();
 };

#endif
