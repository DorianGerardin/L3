#ifndef Strophe_h
#define Strophe_h

class Strophe
{
	private:
	Vers ** suiteVers;
	// attribut de type tableau de pointeurs vers des Vers
	// implémente l’agrégation "une strophe se compose de vers"
	int nbVers;
	
	public:
	Strophe();
	virtual ~Strophe();
	virtual void saisie(istream& is);
	virtual Vers* vers(int i)const;
	virtual void affiche(ostream& os)const;
};
#endif