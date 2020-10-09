public class ListeChainee {
    private Node debut;
    private int taille;

    public ListeChainee() {
        this.debut = null;
    }

    public void ajoutTete(int element) {
        Node premier = new Node(element, this.debut);
        this.debut = premier;
        this.taille++;
    }

    public int longueur() {
        Node iterateur = this.debut;
        int longueur = 0;
        while (iterateur.suivant != null) {
            longueur++;
            iterateur = iterateur.suivant;
        }
        return longueur;
        //return this.taille;
    }

    @Override
    public String toString() {
        Node iterateur = this.debut;
        String affichage = "Taille liste : " + this.taille + " \n \tListeChainee = { ";
        while (iterateur != null) {
            affichage += iterateur.valeur;
            iterateur = iterateur.suivant;
            affichage += ", ";
        }
        return affichage.substring(0, affichage.length() - 2) + " }";
    }

    public ListeChainee renverser() {
        ListeChainee lr = new ListeChainee();
        Node iterateur = this.debut;
        while (iterateur != null) {
            lr.ajoutTete(iterateur.valeur);
            iterateur = iterateur.suivant;
        }
        return lr;
    }

    private class Node {
        private int valeur;
        private Node suivant;

        private Node(int valeur) {
            this.valeur = valeur;
            this.suivant = null;
        }

        private Node(int valeur, Node suivant) {
            this.valeur = valeur;
            this.suivant = suivant;
        }
    }

    public static void main(String[] args) {
        ListeChainee lc = new ListeChainee();
        lc.ajoutTete(5);
        lc.ajoutTete(4);
        lc.ajoutTete(3);
        lc.ajoutTete(2);
        lc.ajoutTete(1);
        lc.ajoutTete(0);
        System.out.println("Liste normale : \n \t" + lc);
        System.out.println("Liste renversée : \n \t" + lc.renverser());
        System.out.println("Liste normale : \n \t" + lc);
    }

}


