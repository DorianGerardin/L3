#include "Assoc.h"
#include "Dico.h"
#include<string>

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::Assoc(){}

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::Assoc(TypeCle c, TypeValeur v) :cle(c), valeur(v){}

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::~Assoc(){}

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::getCle()const {
	return cle;
}

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::setCle(TypeCle c){
	cle = c;
}

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::getValeur()const {
	return valeur;
}

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::setValeur(TypeValeur v){
	valeur = v;
}

template<typename TypeCle, TypeValeur>
Assoc<TypeCle, TypeValeur>::affiche(ostream& os)const {
	os << "Assoc : { " << endl 
	<< "cle : " << cle << endl 
	<< "valeur : " << valeur << endl 
	<< "}";
}

