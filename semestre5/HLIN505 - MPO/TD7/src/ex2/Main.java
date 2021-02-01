package ex2;

import ex3.CollectionFeuillesSalaire;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        FeuilleSalaire fs = new FeuilleSalaire(
                "Apple",
                "Will",
                35,
                2500.0);

        FeuilleSalaire fs2 = new FeuilleSalaire(
                "Google",
                "Jacques",
                27,
                2500.0);

        FeuilleSalaire fs3 = new FeuilleSalaire(
                "Microsoft",
                "Mikael",
                82,
                2500.0);

        System.out.println("tout l'objet : ");
        System.out.println(fs);
        System.out.println("juste les nombres : ");
        fs.afficherNbres();

    }

}
