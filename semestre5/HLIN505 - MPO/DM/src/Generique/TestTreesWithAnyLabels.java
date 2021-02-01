package Generique;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.function.Executable;

import java.util.EmptyStackException;

import static org.junit.jupiter.api.Assertions.*;

public class TestTreesWithAnyLabels {

    LNode<String, Integer> root = new LNode<>("root");
    LNode<String, Integer> right;
    LNode<String, Integer> left;

    @BeforeEach
    public void init() {
        left = root.addNewLeftNode("fils1", 1);
        right = root.addNewRightNode("fils2", 2);
    }

    @Test
    void testLTrees3nodes() {
        assertEquals("root 1 fils1 2 fils2", root.dfsdump());
    }


    @Test
    void testLTrees4nodes() {
        left.addNewLeftNode("fils3", 3);
        assertEquals("root 1 fils1 3 fils3 2 fils2", root.dfsdump());
    }


    @Test
    void testLTrees6nodes() {
        LNode<String, Integer> autre = left.addNewLeftNode("fils3", 3);
        autre.addNewLeftNode("fils4", 4);
        autre.addNewRightNode("fils5", 5);
        assertEquals("root 1 fils1 3 fils3 4 fils4 5 fils5 2 fils2", root.dfsdump());
    }

    @Test
    void testLTreesIterate() {
        LNode<String, Integer> autre = left.addNewLeftNode("fils3", 3);
        autre.addNewLeftNode("fils4", 4);
        autre.addNewRightNode("fils5", 5);

        String trace = "";

        LNodeIterator<String, Integer> nodeIte = new LNodeIterator<>(root);

        while(nodeIte.hasNext()) {
            trace += nodeIte.next().getLabel() + " ";
        }

        assertEquals("root fils1 fils3 fils4 fils5 fils2 ", trace);
    }

    @Test
    void testLTreesIterateWhenNoChildren() {
        LNodeIterator<String, Integer> nodeIte = new LNodeIterator<>(root);
        while(nodeIte.hasNext()) {
            nodeIte.next();
        }
        assertThrows(EmptyStackException.class, nodeIte::next);
    }

}
