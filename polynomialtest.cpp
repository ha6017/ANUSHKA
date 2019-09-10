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
    vector<double> v1;

    

    while(infile>>word)
    {
        //cout<<word<<endl;
        if(word == "init"){ 
            polynomial obj1;    
            cout<<"calling init"<<endl;
            infile>>n;
            obj1.init(n);
            //obj1.display();
            
            while(infile>>word){
                if(word == "init"){
                    break;
                }
                else if(word == "coeff_p1"){
                    cout<<"calling coeff_p1"<<endl;
                    infile>>m;
                    for(int i=0;i<n;i++){
                        infile>>m;
                        cout<<"m= "<<m<<endl;
                        v.push_back(m); // v[0]==m;
                        if(i!=(n-1)) infile>>word;
                    }
                    obj1.coeff_p1(v); 
                }
                else if(word == "get"){
                    cout<<"calling get"<<endl;
                    //polynomial obj2;
                    infile>>m;
                    for(int i=0;i<n;i++){
                        infile>>m;
                        v1.push_back(m); // v[0]==m;
                        cout<<"v1["<<i<<"]="<<v[i]<<endl;
                        if(i!=(n-1)) infile>>word;
                    }
                    bool check = obj1.get(v1);
                    cout<<"check="<<check<<endl;
                }
                else if(word=="eval"){
                    cout<<"calling eval"<<endl;
                    double o;
                    infile>>o;
                    infile>>m;
                    bool check2 = obj1.eval(o,m);
                    obj1.display();
                }

            }
        }
    }
    
    return 0;
}