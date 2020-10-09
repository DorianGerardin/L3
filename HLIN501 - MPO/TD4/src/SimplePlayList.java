import java.util.ArrayList;
import java.io.*;

public class SimplePlayList extends AbstractAudioElement implements Playlist {

    private ArrayList<Song> songList = new ArrayList<>();
    private String title;
    private long duration = 0;
    private long size;

    public SimplePlayList(String title, String fileLocation) throws IOException{
        super(title, fileLocation);

        if (super.getFile().exists()) {
            BufferedReader lecturefichier = new BufferedReader(new FileReader(fileLocation));
            this.title = getTitle();
            String lineString = lecturefichier.readLine();
            lineString = lecturefichier.readLine();
            while (lineString != null) {
                String[] tabS = lineString.split("/");
                long songDuration = Integer.parseInt(tabS[3]);
                lineString = lecturefichier.readLine();
                try {
                    Song song = new Song(tabS[0], tabS[1], tabS[2], songDuration);
                    songList.add(song);
                } catch (IncorrectFileNameException i) {
                    System.out.println("Le fichier " + i.getFileLocationException() + " est incorrect \n");
                }
            }
            this.size = super.getFile().length();
            if (this.songList != null) {
                for (Song s : songList) {
                    this.duration += s.getDuration();
                    this.size += s.getSize();
                }
            }
            lecturefichier.close();
        } else {
            BufferedWriter ecritureFichier = new BufferedWriter(new FileWriter(fileLocation));
            ecritureFichier.write(title); //TQ pas chaine vide
            ecritureFichier.close();
        }
    }

    public void addSong(Song s) {
        songList.add(s);
    }

    @Override
    public long getSize() {
        return size;
    }

    @Override
    public long getDuration() {
        return duration;
    }

    @Override
    public int getNbElement() {
        return songList.size();
    }

    @Override
    public String toString() {
        String affichage = "SimplePlayList : " +
                ", title='" + title + '\'' +
                ", size='" + size + '\'' +
                ", duration=" + duration + "\n";
        int i = 0;
        for (Song s : songList) {
            affichage += "Song " + i + "\n" + s.toString() + "\n";
            i++;
        }
        return affichage;
    }
}
