import java.util.ArrayList;

public enum Lieu {

    Stade1("stade philipides"),
    Stade2("s2"),
    Gymnase1("g1"),
    Gymnase2("g2");

    private String nom;
    private ArrayList<Creneau> creneaux = new ArrayList<>();

    private Lieu(String nom) {
        this.nom = nom;
    }

    public void addCreneau(Creneau c) {
        creneaux.add(c);
    }

    public boolean estDispoPendantCreneau(Creneau c) {
        return !creneaux.contains(c);
    }

}
