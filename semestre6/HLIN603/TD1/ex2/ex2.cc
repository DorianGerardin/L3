#include <iostream> 
class Account {
    public:
        float Balance; 
    public:
        Account(){cout << " Account " << endl; Balance=0;} 
        virtual ~Account(){ cout << " Balancing account, pay " << Balance << " to the client" << endl; }

        virtual void deposit(float f){Balance+=f;}
};

class Remunerative_Account : virtual public Account {

    public:
        Remunerative_Account() {cout << " Remunerative_Account "<< endl;}
        virtual ~Remunerative_Account(){Balance*=1.1;} // 301 * 1.10 = 331.10
        
        virtual void deposit(float f) {Balance+=f; Balance*=1.01;} // on ajoute 401 au 
};

class Deposit_Account : virtual public Account {
    public: 
        Deposit_Account(){cout << " Deposit_Account "<< endl;}
        virtual ~Deposit_Account(){Balance-=100;}  // 401 - 100 = 301
        
        virtual void deposit(float f){
            if(f<=1000){
                Balance+=f-1;
            }else{
                Balance += f + 10;
            }
        }
};

