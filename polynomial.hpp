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
            cout<<"reached cp1"<<endl;
        }

        bool get(const vector<double> v){
            node *temp;
            temp=head;
            int count=0;
            int i=0;
            while(temp!=NULL)
            {
                if(temp->data == v[i]) count++;
                temp=temp->next;
                i++;
            }
            cout<<"count ="<<count<<endl;
            cout<<v.size()<<endl;
            if(count == v.size()){
                return true;
            }else{
                return false;
            }
        }

        bool eval(double x, double y){
            double current_val=0.0;
            double val;
            struct node *temp;
            temp=head;
            int i=0;
            while(temp!=NULL)
            {
                val=temp->data*pow(x,i);
                temp=temp->next;
                current_val+=val;
                i++;
            }
            
            if(current_val==y){
                cout<<"success"<<endl;
                return true;
            }
            else{
                cout<<"failure"<<endl;
                return false;
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
