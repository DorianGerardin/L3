public class Song extends AbstractAudioElement{

    private String singer;
    private int duration;

    public Song(String title, String fileLocation, String singer, int duration) throws IncorrectFileNameException {
        super(title, fileLocation);
        this.singer = singer;
        this.duration = duration;

        if (!super.getFile().exists())
            throw new IncorrectFileNameException(fileLocation);

    }

    @Override
    public long getSize() {
        return super.getFile().length();
    }

    @Override
    public int getDuration() {
        return 1;
    }

    @Override
    public String toString() {
        return "Song : \n" +
                "\t title : " + super.getTitle() +
                "\n\t singer : " + singer +
                "\n\t duration : " + duration;

    }
}
