public class Song extends AbstractAudioElement{

    private String singer;
    private long duration;

    public Song(String title, String fileLocation, String singer, long duration) throws IncorrectFileNameException {
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
    public long getDuration() {
        return duration;
    }

    @Override
    public String toString() {
        return "\t title : " + super.getTitle() +
                "\n\t singer : " + singer +
                "\n\t duration : " + duration +
                "\n\t fileLocation : " + super.getFileLocation();

    }
}
