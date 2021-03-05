#ifndef vers_h 
#define vers_h

class Vers{
	private:
	string suiteMots; // suiteMots, attribut de type string
	string rime; // rime, attribut de type string

	public:
	Vers(); explicit 
	Vers(string s); 
	Vers(string s, string r);
	virtual ~Vers();
	virtual string getSuiteMots()const;
	virtual void setSuiteMots(string sm);
	virtual string getRime()const; virtual void setRime(string r);
	virtual void saisie(istream& is);
	virtual void affiche(ostream& os)const;
};
#endif