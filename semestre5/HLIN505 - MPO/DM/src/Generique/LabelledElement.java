package Generique;

public abstract class LabelledElement<TypeLabel> {
    private TypeLabel label;

    public LabelledElement(TypeLabel label) {
        this.label = label;
    }

    public TypeLabel getLabel() {
        return label;
    }
}