public class Stand implements IStand {

    private String descriptif = "inconnu";
    private int duree;
    private double surface;

    public Stand(String descriptif, int duree, double surface) {
        this.descriptif = descriptif;
        this.duree = duree;
        this.surface = surface;
    }

    @Override
    public String descriptif() {
        return descriptif;
    }

    @Override
    public int duree() {
        return duree;
    }

    @Override
    public double surface() {
        return surface;
    }


}
