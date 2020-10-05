import java.io.IOException;

public class Main {

    public static void main(String[] args) {

        try {
            Song s1 = new Song("What is love", "TD4.iml", "Dany Boon", 180);
            SimplePlayList p1 = new SimplePlayList("playlist1", "playlist.txt");
            System.out.println("nb element p1 : " + p1.getNbElement());
            System.out.println("playlist1 : " + p1.toString());
        } catch (IncorrectFileNameException i) {
            System.out.println("Le fichier " + i.getFileLocationException() + " est incorrect \n");
        } catch (IOException e) {
            System.out.println("Erreur " + e.getMessage());
        }
    }
}
