package ex4;

import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.OptionalInt;
import java.util.stream.Collectors;

public class Promotion {

    private List<Etudiant> listeEtu;

    public Promotion(List<Etudiant> listeEtu) {
        this.listeEtu = listeEtu;
    }

    public Optional<Integer> minAge() {
        return listeEtu
                .stream()
                .filter(e -> e.getModalite() == ModaliteCandidature.eCandidat)
                .map(Etudiant::getAge)
                .min(Comparator.naturalOrder());
    }

    public long nbEtudiant(ModaliteCandidature m) {
        return listeEtu
                .stream()
                .filter(e -> e.getModalite() == ModaliteCandidature.eCandidat)
                .count();
    }

    public List<Etudiant> getListeEtuWithAgeMax() {
        Optional<Integer> maxAge = listeEtu
                .stream()
                .map(Etudiant::getAge)
                .max(Comparator.naturalOrder());
        return listeEtu
                .stream()
                .filter(e -> new Integer(e.getAge()).equals(maxAge.get()))
                .collect(Collectors.toList());
    }

}
