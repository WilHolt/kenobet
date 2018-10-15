/**
 * @file kenobet.cpp
 * @brief this is the functions implementation file of project
 * 
*/
 #include <iostream>
 #include "kenobet.h" 

 /** 
  * @brief Adds a number to the spots only if the number is not already there .
  * @param spot_ The number we wish to include in the bet.
  * @return T if number chosen is successfully inserted ; F otherwise . */
bool KenoBet::add_number( number_type spot_ ){

    if(spot_ >= 1 && spot_ <= 80){
        bet.push_back(spot_);
    }
    return true;
}
 /**
  * @brief Sets the amount of money the player is betting .
  * @return True if we have a wage above zero ; false otherwise .
  * @param wage_ The wage .  
 */
bool KenoBet::set_wage(cash_type wage_ ){
    m_wage = wage_;
    if(wage_ == 0 || wage_ < 0){
        return false;
    }
    return true;
}
 /*! Retrieves the player ’s wage on this bet.
 @return The wage value . */
cash_type KenoBet::get_wage(void) const {
    return m_wage;
}

void KenoBet::reset( void ){
    m_wage = 0;
    bet.erase(bet.begin(), bet.end());
    round_qtd=0;
}

 /** @brief
  *  Check if the player have hit.
  *  @return True if we have a hit ; false otherwise . */

bool KenoBet::check(){
	int bet_price=0;
	int payout_price = 0;
	int hit_count = 0 ;
	std::vector<number_type> hits;
	std::string s_hits(" ");
	// check the hits
	while(round_count <= round_qtd){
        sleep_for(seconds(1));
		roll_turn();

       		for(unsigned int i = 0; i<20; i++){
                   for(int k = 0; k< round_qtd ; k++){
			 	        if(turn[i] == bet[k]){
				            hits.push_back(turn[i]);
				            hit_count++;
                            }
                   }
	 }
	 // transform a array of hits in a string
	 	for(unsigned int i = 0; i< hits.size(); i++){
		std::string aux = std::to_string(hits[i]);
		s_hits.append(aux);
        s_hits += ' ';
	}
	// updating wage
	bet_price= m_wage / round_qtd;
	payout_price = bet_price*payout[hit_count][hit_count];
	m_wage += payout_price;


	
	std::cout<<"This is round #"<<round_count<<" of "<<round_qtd<<", and your wage is $"<< bet_price <<". Good luck!" <<std::endl
	<<"The hits are: [";
	for(int i= 0; i<20; i++){
		std::cout<<" " << turn[i];
	}
	std::cout << "]";

	std::cout<<"\nYou hit the following number(s) ["<< s_hits
	<< " ]a total of " << hit_count <<" hits out of 3"
	<<"\nPayout rate is "<<payout[hit_count-1][hit_count]<<" , thus you came out with: $"<< payout_price
	<<"\nYour net balance so far is: $"<< m_wage <<" dollars."<<std::endl
	<<"--------------------------------------------------"<<std::endl;
	round_count++;
	turn.erase(turn.begin(), turn.end());
	hits.erase(hits.begin(),hits.end());
	s_hits.erase(s_hits.begin(),s_hits.end());
    hit_count = 0;
	}

return true;
 }
 /** @brief 
  * Generate 20 random numbers every round
  * @return void . */
void KenoBet::roll_turn(){
	std::random_device rd;
    std::mt19937 e{rd()}; // or std::default_random_engine e{rd()};
    std::uniform_int_distribution<int> dist{1, 80};
            for (auto i = 0; i < 20; ++i) {
             turn[i] = dist(rd);
    }
}
bool KenoBet::set_rounds( number_type rounds_ ){
	round_qtd =  rounds_;
    if(rounds_ == 0 || rounds_ < 0){
        return false;
    }
	return true;
} 
/** @brief Show Vector of Bets
 * @return void . */
void KenoBet::show_bets(){
	std::cout<<"[";
	for(unsigned int i =0; i<bet.size(); i++){
		std::cout<<bet[i]<< " ";
	}
		std::cout<<"]"<<std::endl;
}

 /** @brief Show Payout Table
  *  @return void . */
void KenoBet::show_payout(){
	std::cout<<"-------+---------"<<std::endl
        <<"Hits | Payout"<<std::endl
        <<"-------+---------"<<std::endl;
		std::vector<cash_type> aux = payout[round_qtd-1];
        for(unsigned int i= 0 ; i<aux.size();  i++){
        std::cout<< i <<" | "<<aux[i]<<std::endl;
        }
}