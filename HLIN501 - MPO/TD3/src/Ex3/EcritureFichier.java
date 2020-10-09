package Ex3;

import java.io.*;

public class EcritureFichier {

    public static void main(String[] args) throws IOException {
        BufferedReader lectureClavier = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Entrez le nom du fichier");
        String nomFichier = lectureClavier.readLine();

        BufferedWriter ecritureFichier = new BufferedWriter(new FileWriter(nomFichier + ".txt"));

        System.out.println("Entrez des lignes (Return pour terminer)");
        String s = lectureClavier.readLine();
        while(s.length() != 0) {
            ecritureFichier.write(s); //TQ pas chaine vide
            ecritureFichier.newLine();
            s = lectureClavier.readLine();
        }
        ecritureFichier.close(); // ferme le fichier associé
        System.out.println("Fin saisie");
    }

}
