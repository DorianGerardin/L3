package Generique;

public class LEdge<TypeLabelE, TypeLabelN> extends LabelledElement<TypeLabelE> {

    private LNode<TypeLabelN, TypeLabelE> father;
    private LNode<TypeLabelN, TypeLabelE> son;

    public LEdge(TypeLabelE label, LNode<TypeLabelN, TypeLabelE> father, LNode<TypeLabelN, TypeLabelE> son) {
        super(label);
        this.father = father;
        this.son = son;
    }

    public LNode<TypeLabelN, TypeLabelE> getFather() {
        return father;
    }

    public LNode<TypeLabelN, TypeLabelE> getSon() {
        return son;
    }

}
