package ex1;

import ex1.CPile;

public class Main {

    public static void main(String[] args) {
        CPile<String> pString = new CPile<>();
        pString.empile("1");
        pString.empile("2");
        pString.empile("3");
        System.out.println("apres empile \n" + pString);
        System.out.println("apres empile nb elements " + pString.nbElements());
        pString.depile();
        System.out.println("apres depile \n" + pString);
        System.out.println("apres depile nb elements " + pString.nbElements());
    }

}
