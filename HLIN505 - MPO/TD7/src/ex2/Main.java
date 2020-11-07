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

        FeuilleSalaire fs4 = new FeuilleSalaire(
                "Microsoft",
                "Wilson",
                74,
                2500.0);

        FeuilleSalaire fs5 = new FeuilleSalaire(
                "Aperture Science",
                "Dan",
                24,
                2500.0);

        FeuilleSalaire fs6 = new FeuilleSalaire(
                "crocodile Land",
                "Maxime",
                24,
                2500.0);

        ArrayList<FeuilleSalaire> listeFeuilles = new ArrayList<>();
        listeFeuilles.add(fs);
        listeFeuilles.add(fs2);
        listeFeuilles.add(fs3);
        listeFeuilles.add(fs4);
        listeFeuilles.add(fs5);
        listeFeuilles.add(fs6);

        CollectionFeuillesSalaire collectionFs = new CollectionFeuillesSalaire(listeFeuilles);

        //q3
        //System.out.println("Non trié");
        //collectionFs.print();
        //System.out.println("Trié");
        //collectionFs.tri1();
        //collectionFs.tri2();
        //collectionFs.tri3();
        //collectionFs.print();

// q4
//        System.out.println("Feuilles Salaires Microsoft : ");
//        List<FeuilleSalaire> fsMicrosoft = collectionFs.getFsByCompany("Microsoft");
//        fsMicrosoft
//                .forEach(System.out::println);
//
//        System.out.println();
//
//        System.out.println("Feuilles Salaires Apple : ");
//        List<FeuilleSalaire> fsApple = collectionFs.getFsByCompany("Apple");
//        fsApple
//                .forEach(System.out::println);

        List<String> fsAp = collectionFs.getCompanyWhichContains("cro");
        fsAp.forEach(System.out::println);

    }

}
