
/**
 * @file main.cpp
 * @author Jose Wilder
 * @author Emerson Freire
 * @brief this is the main file of project
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>// sleep_for, sleep_until
#include <thread>// nanoseconds, system_clock, seconds

#include "kenobet.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

int main(int argc, char const *argv[])
{
	string filename (argv[1] );
    string line;
    string number;
    number_type number_;
    cash_type wage_;
    number_type rounds_ =0;
    string array_bet;
    ifstream file ;
    file.open(filename);
    KenoBet game;
    cout<<">>> Preparing to read bet file ["<<filename<<"], please wait..."<<endl; 
    for(auto i = 0; i<3; i++){
        if(i==0){ // set wage;
        getline(file,line);       
        wage_ =(float) stoi(line,nullptr,10);
        game.set_wage(wage_);
        }else if(i==1){
        getline(file,line);
        rounds_ = stoi(line,nullptr,10);
        game.set_rounds(rounds_);
        }else if(i==2){
            	int max = 1;
             
                 while(getline(file,number,' ')){
                         number_ = stoi(number,nullptr,10);
                         game.add_number(number_);
                }

        }else{
        getline(file,line);
        }
    }
            sleep_for(seconds(2));
        //system("clear");
        int waggin = (wage_/rounds_);
    cout<<"-------------------------------------------------------"<<endl; 
        cout<<">>> Bet successfully read!\n You are going to wage a total of $"<< wage_ <<" dollars.\n"
        <<"Going for a total of "<< rounds_ <<" rounds, waging $"<<waggin<<" per round."<<endl
        <<"Your bet has 3 numbers. They are: ";
        game.show_bets();
        game.show_payout();
    cout<<"-------------------------------------------------------"<<endl; 
        sleep_for(seconds(2));
       // system("clear");
        game.roll_turn();
        game.check();
    
}