public class HallePotiers extends HalleThematique<StandPotier> {

    public double consoEauHoraireMoyenne() {
        return this.getListeStands()
                .stream()
                .mapToDouble(StandPotier::getConsoEau)
                .average()
                .getAsDouble();
    }

}
