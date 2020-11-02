package ex2;

import ex1.FeuSimple;

import java.util.Iterator;

public class FeuilleSalaire implements Iterable<Object>{

    private String employeur, salarie;
    private Integer nombreHeures;
    private Double montantNet;

    public FeuilleSalaire(String employeur, String salarie,
                          Integer nombreHeures, Double montantNet) {
        this.employeur = employeur;
        this.salarie = salarie;
        this.nombreHeures = nombreHeures;
        this.montantNet = montantNet;
    }


    @Override
    public Iterator<Object> iterator() {
        return new IterateurFS();
    }

    class IterateurFS implements Iterator<Object>{

        FeuilleSalaire f;
        private Object[] tab = new Object[5];
        private int i = 0; //compteur

        public IterateurFS() {
            FeuilleSalaire fs = FeuilleSalaire.this;
            f = fs;
            tab[0] = fs.employeur;
            tab[1] = fs.salarie;
            tab[2] = fs.nombreHeures;
            tab[3] = fs.montantNet;
        }

        @Override
        public boolean hasNext() {
            return i < tab.length - 1;
        }

        @Override
        public Object next() {
            i++;
            return tab[i];
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
}
