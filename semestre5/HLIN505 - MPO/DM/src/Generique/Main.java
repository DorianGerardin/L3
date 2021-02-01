package Generique;

import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        LNode<String, Integer> root = new LNode<>("root");
        LNode<String, Integer> right = root.addNewRightNode("fils1", 1);
        LNode<String, Integer> left = root.addNewLeftNode("fils2", 2);

        left.addNewRightNode("fils3", 3);
        right.addNewRightNode("fils4", 4);
        left.addNewLeftNode("fils5", 5);

        LNodeIterator<String, Integer> nodeIte = new LNodeIterator<>(root);

//        while(nodeIte.hasNext()) {
//            System.out.println(nodeIte.next().getLabel());
//        }

        for (LNode<String, Integer> node: root) {
            System.out.println(node.getLabel());
        }
    }

}
