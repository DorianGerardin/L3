package ex4;

public class Etudiant {

    private String name;
    private int age;
    private ModaliteCandidature modalite;

    public Etudiant(String name, int age, ModaliteCandidature modalite) {
        this.name = name;
        this.age = age;
        this.modalite = modalite;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public ModaliteCandidature getModalite() {
        return modalite;
    }

    @Override
    public String toString()
    {
        return getName() + " " + getAge() + " " + modalite;
    }
}
