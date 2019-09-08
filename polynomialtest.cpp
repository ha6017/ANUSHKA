#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<iostream>

#include "polynomial.hpp"

using namespace std;

int main(){

    ifstream infile;
    infile.open("input1.in");
    if(!infile.is_open())
    {
        cout<<"the file couldnt be opened\n";
        exit(EXIT_FAILURE);
    }

    int n;
    string word;

    polynomial obj1;

    while(infile>>word)
    {
        //cout<<word<<endl;
        if(word == "init"){     
            cout<<"calling init"<<endl;
            infile>>n;
            obj1.init(n);
            //obj1.display();
        }
        else if(word == "coeff_p1"){
            cout<<"calling coeff_p1"<<endl;
            
        }
    }
    
    return 0;
}