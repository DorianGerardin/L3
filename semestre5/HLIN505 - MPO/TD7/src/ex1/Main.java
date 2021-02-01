package ex1;

import java.awt.*;
import java.util.Iterator;
import java.util.List;

public class Main {

    public static void main(String[] args) {
// ex1 debut
//        FeuSimple feu = new FeuSimple();
//        List<Color> listeCouleurs = feu.getListeCouleurs();
//        Iterator<Color> itec = listeCouleurs.iterator();
//
//        while(itec.hasNext()) {
//            System.out.println(itec.next());
//        }

// ex1 apres
//        FeuSimple feu = new FeuSimple();
//        IterateurFeu iteFeu = new IterateurFeu(feu);
//        while (iteFeu.hasNext()) {
//            System.out.println(iteFeu.next());
//        }

        FeuSimple feu = new FeuSimple();
        Iterator<Color> itec = feu.iterator();

        while(itec.hasNext()) {
            System.out.println(itec.next());
        }

    }

}
