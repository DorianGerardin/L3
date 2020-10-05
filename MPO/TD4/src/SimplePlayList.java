import java.util.ArrayList;
import java.io.*;

public class SimplePlayList extends AbstractAudioElement implements Playlist {

    private ArrayList<Song> songList;
    private String format;
    private String title;

    private static int nbPlaylist = 0;

    public SimplePlayList(String title, String fileLocation) throws IOException{
        super(title, fileLocation);

        if (super.getFile().exists()) {
            BufferedReader lecturefichier = new BufferedReader(new FileReader(fileLocation));
            String s = lecturefichier.readLine();
            while (s != null) {
                s = lecturefichier.readLine();

            }
            lecturefichier.close();
            System.out.println("Fin du fichier");
        } catch (IncorrectFileNameException i) {
            System.out.println("Le fichier " + i.getFileLocationException() + " est incorrect \n");
        }
        } else {
            BufferedWriter ecritureFichier = new BufferedWriter(new FileWriter("Playlist" + nbPlaylist + ".txt"));
            while(title.length() != 0) {
                ecritureFichier.write(title); //TQ pas chaine vide
            }
            ecritureFichier.close();
            nbPlaylist++;
        }
    }

}
