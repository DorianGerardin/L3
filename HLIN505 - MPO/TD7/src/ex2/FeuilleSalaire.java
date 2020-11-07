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

    public Integer getNombreHeures() {
        return nombreHeures;
    }

    public String getEmployeur() {
        return employeur;
    }

    @Override
    public Iterator<Object> iterator() {
        return new IterateurFS();
    }

    @Override
    public String toString() {
        return "FeuilleSalaire{" +
                "employeur='" + employeur + '\'' +
                ", salarie='" + salarie + '\'' +
                ", nombreHeures=" + nombreHeures +
                ", montantNet=" + montantNet +
                '}';
    }

    class IterateurFS implements Iterator<Object>{

        FeuilleSalaire f;
        private Object[] tab = new Object[4];
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
            return i < tab.length;
        }

        @Override
        public Object next() {
            i++;
            return tab[i-1];
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
}
