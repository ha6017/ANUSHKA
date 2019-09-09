#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>

using namespace std;

struct node
{
    double data;
    node *next;
};

class polynomial{
    private: 
        node *head;
        node *tail;

    public: 
        polynomial(){
            head = NULL;
            tail = NULL;
        }

        void init(int num){
            if(num > 0){
                for(int i=0;i<num;i++){
                    node *tmp = new node;
                    tmp->data = 0;
                    tmp->next = NULL;
                    if(head == NULL)
                    {
                        head = tmp;
                        tail = tmp;
                    }
                    else
                    {
                        tail->next = tmp;
                        tail = tail->next;
                    }
                    //cout<<"node added"<<endl;
                }      
            }
        }

        void coeff_p1(const vector<double> v){
            struct node *temp;
            temp=head;
            int i=0;
            while(temp!=NULL)
            {
                temp->data = v[i];
                temp=temp->next;
                i++;
            }
        }

        void display()
        {
            node *temp;
            temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    
};
