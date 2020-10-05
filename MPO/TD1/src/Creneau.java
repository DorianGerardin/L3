public class Creneau {

    private JourSemaine jour;
    private Heure heureDebut;
    private Heure heureFin;

    public Creneau(JourSemaine jour, Heure heureDebut, Heure heureFin) {
        this.jour = jour;
        this.heureDebut = heureDebut;
        this.heureFin = heureFin;
    }

    public boolean chevauche(Creneau c) {
        if (this.jour.equals(c.jour)) {
            boolean commenceAvantEtFinitPdt = this.heureDebut.estAvant(c.heureDebut) && !this.heureFin.estAvant(c.heureFin);
            boolean commencePdtEtFinitApres = !this.heureDebut.estAvant(c.heureDebut) && !this.heureFin.estAvant(c.heureFin);
            return true;
        } else return false;
    }

    public boolean estInclusDans(Creneau c) {
        return !this.heureDebut.estStrictementAvant(c.heureDebut) && this.heureFin.estStrictementAvant(c.heureFin);
    }
}
