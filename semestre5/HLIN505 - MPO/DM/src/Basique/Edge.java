package Basique;

public class Edge {

    private String label;
    Node father;
    Node son;

    public String getLabel() {
        return label;
    }

    public Edge(String label, Node father,
                Node son) {
        this.label=label;
        this.father = father;
        this.son = son;
    }

    public Node getFather() {
        return father;
    }

    public Node getSon() {
        return son;
    }

}
