import java.util.ArrayList;

public class FileAttenteGenerique<A> {

    protected ArrayList<A> contenu;

    public FileAttenteGenerique(){
        contenu = new ArrayList<>();
    }

    public void entre(A p) {
        contenu.add(p);

    }
    public A sort() {
        A a = null;
        if (!contenu.isEmpty()) {
            a = contenu.get(0);
            contenu.remove(0);
        }
        return a;
    }

    public boolean estVide(){return contenu.isEmpty();}
    public String toString(){return ""+contenu;}

}
