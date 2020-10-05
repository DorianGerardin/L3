import java.util.ArrayList;

public class Biblio {

    private ArrayList<Document> listeReferences = new ArrayList<>();

    public Biblio() {

    }

    public void ajoutDocument(Livre l) {
        listeReferences.add(l);
        System.out.println("Ajout livre de " + l);
    }

    public void ajoutDocument(Document d) {
        listeReferences.add(d);
        System.out.println("Ajout doc de " + d);
    }

    public boolean contains(Document d) {
        return listeReferences.contains(d);
    }

    @Override
    public String toString() {
        return "Biblio [listeReferences = " + listeReferences + "]";
    }
}
