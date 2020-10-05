public class Main {

    public static void main(String[] args) {
        Heure h1 = new Heure(10, 50);
        Heure h2 = new Heure(11, 5);
        Heure hbad = new Heure(11, 2);

        Creneau c1 = new Creneau(JourSemaine.LUNDI, h1, h2);
        Creneau c2 = new Creneau(JourSemaine.LUNDI, new Heure(10, 55), new Heure(11, 0));

        System.out.println("hbad = " + hbad);
        System.out.println("h1 = " + h1);
        System.out.println("h2 = " + h2);
        System.out.println("h1 strictement avant h2 = " + h1.estStrictementAvant(h2));
        System.out.println("c2 inclus dans c1 = " + c2.estInclusDans(c1));
    }

}
