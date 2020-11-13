package Generique;

import java.util.Iterator;
import java.util.Stack;

public class LNodeIterator<TypeLabelN, TypeLabelE> implements Iterator<LNode<TypeLabelN, TypeLabelE>> {

    private Stack<LNode<TypeLabelN, TypeLabelE>> noeudRestants;

    public LNodeIterator(LNode<TypeLabelN, TypeLabelE> node) {
        this.noeudRestants = new Stack<>();
        parcoursPrefixe(node);
    }

    public void parcoursPrefixe(LNode<TypeLabelN, TypeLabelE> node) {
        if (node != null) {
            parcoursPrefixe(node.getRightNode());
            parcoursPrefixe(node.getLeftNode());
            noeudRestants.push(node);
        }
    }

    @Override
    public boolean hasNext() {
        return !noeudRestants.isEmpty();
    }

    @Override
    public LNode<TypeLabelN, TypeLabelE> next() {
        return noeudRestants.pop();
    }
}
