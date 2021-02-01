package ex1;

import java.awt.*;
import java.util.ArrayList;
import java.util.Iterator;

public class FeuSimple implements Iterable<Color> {

    private static ArrayList<Color> couleurs = new ArrayList<>();

    public FeuSimple() {
        couleurs.add(Color.green);
        couleurs.add(Color.orange);
        couleurs.add(Color.red);
    }

    public ArrayList<Color> getListeCouleurs() {
        return couleurs;
    }

    @Override
    public Iterator<Color> iterator() {
        return new IterateurFeu(this);
    }
}
