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
    double m;
    string word;
    vector<double> v;

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
            infile>>m;
            for(int i=0;i<n;i++){
                infile>>m;
                v.push_back(m); // v[0]==m;
                infile>>word;
            }
            obj1.coeff_p1(v);
            obj1.display();
        }
    }
    
    return 0;
}