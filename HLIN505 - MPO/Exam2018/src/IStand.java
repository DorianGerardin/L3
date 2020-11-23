public interface IStand {

    String descriptif();
    int duree();
    double surface();
    static double prixLocBaseHM2 = 10;
    default double prixLoc(){
        double pl = this.surface()*this.duree()*IStand.prixLocBaseHM2;
        assert (pl >= 0);
        return pl;
    }

}
