package test;

public class Adherent {

    private String nom;
    //private final String numero;
    private boolean cotisationPayee;
    private int derniereAnneeCotise;
    private static int nbAdherentCrees = 0;

    public Adherent(String nom) {
        Adherent.nbAdherentCrees++;
        this.nom = nom;
    }
}
