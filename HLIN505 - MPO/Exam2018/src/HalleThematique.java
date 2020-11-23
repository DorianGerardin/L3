import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class HalleThematique<TS extends IStand> {
    private String nom = "inconnu";
    private double surface = 0;
    private ArrayList<TS> listeStands = new ArrayList<>();

    public HalleThematique() {
    }

    public List<TS> getListeStands() {
        return Collections.unmodifiableList(this.listeStands);
    }

    public void ajoute(TS i) {
        if (!this.listeStands.contains(i)) this.listeStands.add(i);
    }

    public double prixTotalLocationStandsSurfaceSupA(double s) {
        return getListeStands().stream()
                .filter(st -> st.surface() >= s)
                .mapToDouble(TS::prixLoc)
                .sum();
    }

    public void accueille(HalleThematique<? extends TS> h) {
        this.listeStands.addAll(h.listeStands);
    }
}