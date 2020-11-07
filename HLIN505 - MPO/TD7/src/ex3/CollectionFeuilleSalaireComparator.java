package ex3;

import ex2.FeuilleSalaire;

import java.util.Comparator;

public class CollectionFeuilleSalaireComparator implements Comparator<FeuilleSalaire> {

    @Override
    public int compare(FeuilleSalaire fs1, FeuilleSalaire fs2) {
        return fs1.getNombreHeures().compareTo(fs2.getNombreHeures());
    }
}
