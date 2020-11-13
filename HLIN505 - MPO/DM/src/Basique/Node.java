package Basique;

public class Node {

    Edge leftEdge;
    Edge rightEdge;
    String label;

    public Node(String label) {
        this.label=label;
    }

    public Node addNewLeftNode(String labeln, String labele) {
        Node left=new Node(labeln);
        leftEdge=new Edge(labele, this, left);
        return left;
    }

    public Node addNewRightNode(String labeln, String labele) {
        Node right=new Node(labeln);
        rightEdge=new Edge(labele, this, right);
        return right;
    }

    public String dfsdump() {
        String left = leftEdge != null ? " " + leftEdge.getLabel() + " " + leftEdge.getSon().dfsdump() : "";
        String right = rightEdge != null ? " " + rightEdge.getLabel() + " " + rightEdge.getSon().dfsdump() : "";
        return label + left + right;
    }

    public Node getRightNode(){
        return rightEdge !=null ? rightEdge.getSon() : null;
    }

    public Node getLeftNode(){
        return leftEdge != null ? leftEdge.getSon() : null;
    }
}

