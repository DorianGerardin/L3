import java.io.File;

public abstract class AbstractAudioElement implements ElementAudio{

    private File file;
    private String title;
    private String fileLocation;

    public AbstractAudioElement(String title, String fileLocation) {
        this.title = title;
        this.fileLocation = fileLocation;
        this.file = new File(fileLocation);
    }

    @Override
    public String getFileLocation() {
        return fileLocation;
    }

    @Override
    public String getTitle() {
        return title;
    }

    public File getFile() {
        return file;
    }
}
