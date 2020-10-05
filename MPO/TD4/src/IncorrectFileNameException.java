public class IncorrectFileNameException extends Exception{

    private String fileLocation;

    public IncorrectFileNameException(String fileLocation) {
        this.fileLocation = fileLocation;
    }

    public String getFileLocationException() {
        return this.fileLocation;
    }

}
