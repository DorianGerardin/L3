#include<iostream>
#include<string>
using namespace std;
#include"Dictionnaire.h"

template class Dictionnaire<TypeCle, TypeValeur>;

Dictionnaire::Dictionnaire(){}
Dictionnaire::~Dictionnaire(){}

template<typename TypeCle, typename TypeValeur>
void Dictionnaire<TypeCle, TypeValeur>::CherchCl(TypeCle & c, TypeValeur & v){
	
}

template<typename TypeCle, typename TypeValeur>
void Dictionnaire<TypeCle, TypeValeur>::put(TypeCle & c, TypeValeur & v){

}
