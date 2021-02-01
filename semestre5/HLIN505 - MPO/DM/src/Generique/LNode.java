package Generique;

import java.util.Iterator;

public class LNode<TypeLabelN, TypeLabelE> extends LabelledElement<TypeLabelN> implements Iterable<LNode<TypeLabelN, TypeLabelE>> {

    private LEdge<TypeLabelE, TypeLabelN> leftEdge;
    private LEdge<TypeLabelE, TypeLabelN> rightEdge;

    public LNode(TypeLabelN label) {
        super(label);
    }

    public LNode<TypeLabelN, TypeLabelE> addNewLeftNode(TypeLabelN labeln, TypeLabelE labele) {
        LNode<TypeLabelN, TypeLabelE> left = new LNode<>(labeln);
        leftEdge = new LEdge<>(labele, this, left);
        return left;
    }

    public LNode<TypeLabelN, TypeLabelE> addNewRightNode(TypeLabelN labeln, TypeLabelE labele) {
        LNode<TypeLabelN, TypeLabelE> right = new LNode<>(labeln);
        rightEdge = new LEdge<>(labele, this, right);
        return right;
    }

    public String dfsdump() {
        String left = leftEdge != null ? " " + leftEdge.getLabel() + " " + leftEdge.getSon().dfsdump() : "";
        String right = rightEdge != null ? " " + rightEdge.getLabel() + " " + rightEdge.getSon().dfsdump() : "";
        return getLabel() + left + right;
    }

    public LNode<TypeLabelN, TypeLabelE> getRightNode() {
        return rightEdge != null ? rightEdge.getSon() : null;
    }

    public LNode<TypeLabelN, TypeLabelE> getLeftNode() {
        return leftEdge != null ? leftEdge.getSon() : null;
    }

    public LEdge<TypeLabelE, TypeLabelN> getLeftEdge() {
        return leftEdge;
    }

    public LEdge<TypeLabelE, TypeLabelN> getRightEdge() {
        return rightEdge;
    }

    @Override
    public Iterator<LNode<TypeLabelN, TypeLabelE>> iterator() {
        return new LNodeIterator<>(this);
    }
}
