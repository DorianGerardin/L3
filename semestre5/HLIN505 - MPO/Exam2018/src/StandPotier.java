public class StandPotier extends Stand {

    private double consoElec;
    private double consoEau;

    public StandPotier(String descriptif, int duree, double surface, double consoElec, double consoEau) {
        super(descriptif, duree, surface);
        this.consoElec = consoElec;
        this.consoEau = consoEau;
    }

    public double getConsoElec() {
        return consoElec;
    }

    public double getConsoEau() {
        return consoEau;
    }
}
