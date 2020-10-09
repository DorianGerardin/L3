package Ex3;

import java.io.*;

public class LectureFichier {

    public static void main(String[] args) throws IOException {

        BufferedReader lectureClavier = new BufferedReader(new InputStreamReader(System.in));

        boolean isValid = false;

        while (!isValid) {
            try {
                System.out.println("Entrez le nom du fichier à lire (Entrée pour arrêter)");
                String scanClavier = lectureClavier.readLine();

                if (scanClavier.length() == 0) {
                    break;
                }

                BufferedReader lecturefichier = new BufferedReader(new FileReader(scanClavier + ".txt"));
                FichierTexte ft = new FichierTexte(scanClavier + ".txt");
                isValid = true;
                System.out.println("Nombre de lignes du fichier  : " + ft.nbreLignes());
                System.out.println("Nombre total de charactères du fichier " + ft.nbCaracteres());
                System.out.println("Contenu du fichier " + scanClavier + ".txt");

                String s = lecturefichier.readLine();
                while (s != null) {
                    System.out.println(s);
                    s = lecturefichier.readLine();
                }
                lecturefichier.close();
                System.out.println("Fin du fichier");
            } catch (FileNotFoundException e) {
                System.out.println("Ce fichier n'existe pas");
            }
        }
    }

}
