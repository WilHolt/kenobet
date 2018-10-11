 #include <iostream>
 #include "conta.h" 

bool KenoBet::add_number( number_type spot_ ){
    bet.push_back(spot_);
    return true;
}
bool KenoBet::set_wage(cash_type wage_ ){
    m_wage = wage_;
    if(wage_ == 0 || wage_ < 0){
        return false;
    }
    return true;
}
cash_type KenoBet::get_wage(void) const {
    return m_wage;
}

void KenoBet::reset( void ){}

