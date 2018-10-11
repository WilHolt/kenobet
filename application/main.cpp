#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>  

using namespace std;

int main(int argc, char const *argv[])
{
	string filename (argv[1] );
    string teste;
    ifstream file ;
    file.open(filename);
    for(auto i = 0; i<3; i++){
        getline(file,teste);
        cout<<teste;
    }

    
}