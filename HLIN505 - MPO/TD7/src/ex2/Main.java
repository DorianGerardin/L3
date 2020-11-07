package ex2;

import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        FeuilleSalaire fs = new FeuilleSalaire(
                "Dupont",
                "Reno",
                35,
                2500.0);

        Iterator<Object> iteFS = fs.iterator();

        while(iteFS.hasNext()) {
            System.out.println(iteFS.next());
        }

    }

}
