import java.util.LinkedList;

public class CPile<A> implements IPile<A> {

    private LinkedList<A> pile = new LinkedList<>();

    @Override
    public boolean estVide() {
        return pile.isEmpty();
    }

    @Override
    public void empile(A a) {
        pile.addFirst(a);
    }

    @Override
    public A depile() {
        return pile.remove();
    }

    @Override
    public int nbElements() {
        return pile.size();
    }

    @Override
    public A sommet() {
        return pile.getFirst();
    }
}
