package ex1;

import java.awt.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class IterateurFeu implements Iterator<Color> {

    private List<Color> listeCouleurs;
    private int compteur;

    public IterateurFeu(FeuSimple feu) {
        listeCouleurs = feu.getListeCouleurs();
        compteur = 0;
    }

    @Override
    public boolean hasNext() {
        return true;
    }

    @Override
    public Color next() {
        Color elt = listeCouleurs.get(compteur);
        compteur = (compteur + 1) % 3;
        return elt;
    }

    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}
