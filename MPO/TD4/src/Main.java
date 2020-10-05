public class Main {

    public static void main(String[] args) {

        try {
            Song s1 = new Song("What is love", "TD4.iml", "Dany Boon", 180);
            System.out.println(s1);
        } catch (IncorrectFileNameException i) {
            System.out.println("Le fichier " + i.getFileLocationException() + " est incorrect \n");
        }
    }
}
