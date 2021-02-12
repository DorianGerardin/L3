#include <iostream> 
using namespace std;

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

class Remunerative_Deposit_Account : virtual public Remunerative_Account, virtual public Deposit_Account {
    public:
        Remunerative_Deposit_Account(){}
        virtual ~Remunerative_Deposit_Account(){} // rien ne se passe
        virtual void deposit(float f) {
            Deposit_Account::Balance+=f+1;
            Remunerative_Account::Balance+=f+1;
        }
};
class Deposit_Account_w_creditCard : virtual public Deposit_Account {};
class Remunerative_Deposit_Account_w_CreditCard : virtual public Deposit_Account_w_creditCard, virtual public Remunerative_Deposit_Account_w_CreditCard {};


main() {

       cout <<"----- opening of a Deposit account-----" <<endl; 
    Deposit_Account *DA = new Deposit_Account;
    DA->deposit(400); 
    cout << " DA balance " << DA->Balance << endl; 
    cout <<"----- closing of a Deposit account-----" <<endl; 
    //RA->end(); 
    delete DA; 

    cout <<"----- opening of a Remunerative account-----" <<endl; 
    Remunerative_Account *RA = new Remunerative_Account;
    RA->deposit(400); 
    cout << " RA balance " << RA->Balance << endl; 
    cout <<"----- closing of a Remunerative account-----" <<endl; 
    //RA->end(); 
    delete RA; 
    
    cout <<"----- opening of a remunerative deposit account-----" <<endl; 
    Remunerative_Deposit_Account *RDA = new Remunerative_Deposit_Account();
    // RDA->Deposit_Account::deposit(800); //cas heritage non virtuel RDA->deposit(800);
    RDA->deposit(400); // ajoute 401 (car pour chq dépot dans ce compte on ajoute 1 euro)
    cout << " RDA balance " << RDA->Deposit_Account::Balance << endl; 
    cout <<"----- closing of a remunerative deposit account-----" <<endl; 
    delete RDA; // on appelle les destructeurs dans l'ordre suivant RDA -> DA -> RA -> A


    cout <<"----- opening of a remunerative deposit account with CC-----" <<endl;
    Remunerative_Deposit_Account_w_Creditcard *RDACC = new Remunerative_Deposit_Account_w_Creditcard();
    RDACC->deposit(800);
    cout <<"current balance before closing: " << RDACC->getBalance() << endl;
    cout <<"----- closing of a remunerative deposit account with CC-----" <<endl;
    delete RDACC;
}


