public class BiblioSansDoublons extends Biblio {

    @Override
    public void ajoutDocument(Livre l) {
        if(!contains(l)) {
            super.ajoutDocument(l);
        }
    }

    @Override
    public void ajoutDocument(Document d) {
        if(!contains(d)) {
            super.ajoutDocument(d);
        }
    }
}
