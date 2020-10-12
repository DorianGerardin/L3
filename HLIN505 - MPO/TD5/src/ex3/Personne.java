package ex3;

public class Personne implements ElementAvecPriorite
{
	private String nom;
	private int age;

	public Personne(){}

	public Personne(String n, int a){
		nom=n;
		age=a;
	}

	public String getNom(){
		return nom;
	}

	public void setNom(String n){
		nom=n;
	}
	public int getAge(){ return age;}
	public void setAge(int a){age=a;}
	public String toString(){return nom+" "+age;}

	@Override
	public int priorite() {
		if (age > 0 && age < 12) {
			return 1;
		} else if (age > 60) {
			return 2;
		} else return 3;

	}

	public static void main(String[] args) {
		FileAttentePrio<Personne> fap = new FileAttentePrio<>();
		Personne p1 = new Personne("Tristan", 11);
		Personne p2 = new Personne("Lea", 61);
		Personne p3 = new Personne("Dorian", 20);
		Personne p4 = new Personne("DorianBis", 20);

		fap.entre(p1);
		fap.entre(p2);
		fap.entre(p3);
		fap.entre(p4);

		System.out.println("dorian prio : " + p3.priorite());
		System.out.println("dorianBis prio : " + p4.priorite());
		System.out.println("Tristan prio : " + p1.priorite());
		System.out.println("Lea prio : " + p2.priorite());

		System.out.println(fap.sort() + " sort");
		System.out.println(fap.sort() + " sort");
		System.out.println(fap.sort() + " sort");
		System.out.println(fap.sort() + " sort");
	}
}

