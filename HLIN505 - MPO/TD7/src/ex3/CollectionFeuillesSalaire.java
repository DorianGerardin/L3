package ex3;

import ex2.FeuilleSalaire;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class CollectionFeuillesSalaire {

    private ArrayList<FeuilleSalaire> listeFeuilles;

    public CollectionFeuillesSalaire(ArrayList<FeuilleSalaire> listeFeuilles) {
        this.listeFeuilles = listeFeuilles;
    }

    public void print() {
        listeFeuilles
                .stream()
                .forEach(System.out::println);
    }

    public void print2() {
        listeFeuilles
                .forEach(f -> System.out.println(f));
    }

    // sans lambdas et sans classes anonymes
    public void tri1() {
        Comparator<FeuilleSalaire> comparatorFS = new CollectionFeuilleSalaireComparator();
        listeFeuilles.sort(comparatorFS);
    }

    // sans lambdas et avec classe anonymes
    public void tri2() {
        Comparator<FeuilleSalaire> comparatorFS = new Comparator<FeuilleSalaire>() {
            @Override
            public int compare(FeuilleSalaire fs1, FeuilleSalaire fs2) {
                return fs1.getNombreHeures().compareTo(fs2.getNombreHeures());
            }
        };
        listeFeuilles.sort(comparatorFS);
    }

    public void tri3() {
        Comparator<FeuilleSalaire> comparatorFS = (fs1, fs2) -> fs1.getNombreHeures().compareTo(fs2.getNombreHeures());
        listeFeuilles.sort(comparatorFS);
    }

    public List<FeuilleSalaire> getFsByCompany(String employeur) {
        return listeFeuilles
                .stream()
                .filter(fs -> fs.getEmployeur().equals(employeur))
                .collect(Collectors.toList());
    }

    public List<String> getCompanyWhichContains(String str) {
        ArrayList<String> companyList = new ArrayList<>();
        listeFeuilles.forEach(fs -> {
            if (!companyList.contains(fs.getEmployeur())) {
                if (fs.getEmployeur().contains(str)) {
                    companyList.add(fs.getEmployeur());
                }
            }
        });
        if (companyList.isEmpty()) {
            companyList.add("No matches");
        }
        return companyList;
    }

}
