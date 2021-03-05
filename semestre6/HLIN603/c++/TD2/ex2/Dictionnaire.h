#ifndef D_h 
#define D_h

using namespace std; 
#include<iostream>
#include <string>
#include "Assoc.h"

template<typename TypeCle, typename TypeValeur>
class Dictionnaire{
	private:
		Assoc<TypeCle, TypeValeur>* tabAssoc;
		int nbAssoc;
		int capacite;

		void CherchCl(const TypeCle& cl, int& i, int& res);

	public:
		Dictionnaire();
		virtual ~Dictionnaire();
		virtual void put(const TypeCle &, const TypeValeur &);
		virtual TypeValeur get(const TypeCle &)const;
		virtual bool estVide()const;
		virtual int taille()const;
		virtual bool contient(const TypeCle &)const;
		virtual void affiche(ostream&)const;
		virtual Dictionnaire& operator=(const Dictionnaire & D);
	protected:
};

template<typename TypeCle, typename TypeValeur>
ostream& operator<<(ostream&, const Dictionnaire<TypeCle, TypeValeur>&;

#endif