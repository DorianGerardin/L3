package ex3;

public class FileAttentePrio<A extends ElementAvecPriorite> extends FileAttenteGenerique<A> {

    @Override
    public A sort() {
        A a = null;
        if (!contenu.isEmpty()) {
            a = contenu.get(0);
            for (A t: contenu) {
                if (t.priorite() < a.priorite()) {
                    a = t;
                }
            }
            contenu.remove(a);
        }
        return a;
    }
}
