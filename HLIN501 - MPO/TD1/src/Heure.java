public class Heure {

    private int heure;
    private int minute;

    private static final int precision = 5;
    private static final int heureMin = 7;
    private static final int heureMax = 23;

    public boolean estValide() {
        return this.heure != -1 && this.minute != -1;
    }

    public Heure(int heure, int minute) {
        if (heure >= heureMin && heure <= heureMax) {
            if (minute%precision == 0) {
                this.heure = heure;
                this.minute = minute;
            } else this.minute = -1;
        } else this.heure = -1;
    }

    @Override
    public String toString() {
        if (!this.estValide()) {
            return "Heure invalide";
        } else return "L'heure est " + this.heure + " h " + this.minute;
    }

    public boolean estMemeHeure(Heure h) {
        return this.heure == h.heure && this.minute == h.minute;
    }

    public boolean estAvant(Heure h) {
        if (this.estMemeHeure(h)) return true;
        if (this.heure < h.heure) return true;
        else if (this.heure == h.heure) {
            return this.minute < h.minute;
        }
        else return false;
    }

    public boolean estStrictementAvant(Heure h) {
        return !this.estMemeHeure(h) && this.estAvant(h);
    }
}
