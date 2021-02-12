#include<string>
using namespace std;

class CompteDepot : virtual public CompteBancaire {
	public	:
		CompteDepot(){
			cout << "Compte dépot : " << endl;
		}

		virtual ~CompteDepot(){
			cout << "Fermeture compte, solde : " << solde << endl;
		}

		virtual void desposit(float f) {
			balance+=f
		}
}
