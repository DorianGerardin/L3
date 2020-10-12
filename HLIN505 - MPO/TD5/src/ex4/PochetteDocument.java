package ex4;

import java.util.ArrayList;

public class PochetteDocument<A extends Document> {

    private String theme;
    private ArrayList<A> pochette;

    public PochetteDocument(String theme) {
        this.theme = theme;
        this.pochette = new ArrayList<>();
    }

    public void ajout(A a) {
        pochette.add(a);
    }
}
