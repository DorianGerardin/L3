package Ex3;

import java.io.*;

public class FichierTexte {

    private File fichier;
    private String contenu;

    public FichierTexte(File unFichier) throws FileNotFoundException {
        if (!unFichier.exists()) throw new FileNotFoundException();
        fichier = unFichier;
    }

    public FichierTexte(String cheminFichier) throws FileNotFoundException {
        fichier = new File(cheminFichier);
        if(!fichier.exists()) throw new FileNotFoundException();
    }

    public int nbreLignes() throws FileNotFoundException, IOException {
        int nb = 0;
        BufferedReader lectureFichier = new BufferedReader(new FileReader(fichier.getAbsolutePath()));
        String s = lectureFichier.readLine();
        while (s != null) {
            nb++;
            s = lectureFichier.readLine();
        }
        lectureFichier.close();
        return nb;
    }

    public int nbCaracteres() throws FileNotFoundException, IOException {
        int nb = 0;
        BufferedReader lectureFichier = new BufferedReader(new FileReader(fichier.getAbsolutePath()));
        String s = lectureFichier.readLine();
        while (s.length() != 0) {
            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i) != ' ') {
                    nb++;
                }
            }
            s = lectureFichier.readLine();;
        }
        return nb;
    }

//    public  contenu() throws FileNotFoundException, IOException {
//        BufferedReader lectureFichier = new BufferedReader(new FileReader(fichier.getAbsolutePath()));
//        String s = lectureFichier.readLine();
//        while (s != null) {
//            contenu = s + '\n';
//            s = lectureFichier.readLine();
//        }
//    }

}
