import java.util.LinkedList;

public class CPile<A> implements IPile<A> {

    private LinkedList<A> pile = new LinkedList<>();

    @Override
    public boolean estVide() {
        return pile.isEmpty();
    }

    @Override
    public void empile(A a) {
        pile.addLast(a);
    }

    @Override
    public A depile() {
        return pile.removeLast();
    }

    @Override
    public int nbElements() {
        return pile.size();
    }

    @Override
    public A sommet() {
        return pile.peekLast();
    }

    @Override
    public String toString() {
        String affichage = "";
        for (A a: pile) {
            affichage += a + "\n";
        }
        return affichage;
    }
}
