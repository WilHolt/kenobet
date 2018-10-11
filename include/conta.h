#ifndef _CONTA_H_
#define _CONTA_H_

#include <iostream>
#include <vector>

using number_type = unsigned short int ; // <! data type for a keno hit.
 using cash_type = float ; // <! Defines the wage type in this application .
 using set_of_numbers_type = std::vector<number_type>;

 class KenoBet{
 private:
	 cash_type m_wage;
	 std::vector<number_type> bet;
	 std::vector<number_type> top;

 public:
 //! Creates an empty Keno bet.
 KenoBet():m_wage (0)
 { /* empty */ };

 /*! Adds a number to the spots only if the number is not already there .
 @param spot_ The number we wish to include in the bet.
 @return T if number chosen is successfully inserted ; F otherwise . */
 bool add_number( number_type spot_ );

 /*! Sets the amount of money the player is betting .
 @param wage_ The wage .
 @return True if we have a wage above zero ; false otherwise . */
bool set_wage( cash_type wage_ );

 //! Resets a bet to an empty state .
void reset( void );

 /*! Retrieves the player ’s wage on this bet.
 @return The wage value . */
cash_type get_wage(void) const ;

 /*! Returns to the current number of spots in the player ’s bet.
 @return Number of spots present in the bet. */
size_t size (void) const;
 };
#endif
