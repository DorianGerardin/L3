package ex1;

import java.lang.reflect.Method;
import java.util.ArrayList;

public class ArrayListMystere {

    private static ArrayList list;
    static ArrayList<ArrayList<Class>> superClasses;

    public ArrayListMystere() {
        list = new ArrayList();
        list.add(1);
        list.add("Hello");
        list.add(2.0);
    }

    public static Method[] getMethods(int i) {
        Object o = list.get(i);
        Class c = o.getClass();
        return c.getMethods();
    }

    public static void main(String[] args) {
        new ArrayListMystere();
//        for (int i = 0; i < list.size(); i++) {
//            Object o = list.get(i);
//            System.out.println("L'élément " + i + " est de classe : " + o.getClass().getName());
//
//            Method[] methodes = getMethods(i);
//            System.out.println("Méthodes : ");
//            for (Method m : methodes) {
//                String m_name = m.getName();
//                Class m_returnType = m.getReturnType();
//                System.out.println(" " + m_returnType.getName() + " " + m_name + "(");
//                Class[] m_paramTypes = m.getParameterTypes();
//                for (int j = 0; j < m_paramTypes.length; j++) {
//                        System.out.println(m_paramTypes[j].getName());
//                }
//                System.out.println(")");
//                System.out.println(", Definie dans " + m.getDeclaringClass().getName());
//            }
//        }
        getCommonSpecific();
    }

    //Q2

    private static ArrayList<Class> getClasses(Object o) {
        ArrayList<Class> sc = new ArrayList<>();
        Class c = o.getClass();
        while(c != null) {
            sc.add(c);
            c = c.getSuperclass();
        }
        return sc;
    }

    private static void fillSuperClass() {
        superClasses = new ArrayList<>();
        for(Object o : list) {
            superClasses.add(getClasses(o));
        }
    }

    private static Class getCommonSpecific() {

        fillSuperClass();

        ArrayList<Class> first = superClasses.get(0);
        Class plusSpecifique = null;
        for (int i = 0; i < first.size() && plusSpecifique == null; i++) {
            String className = first.get(i).getName();
            System.out.println("Comparer : " + className);
            boolean testInAllOthersLists = true;
            for (int j = 1; j < superClasses.size() && testInAllOthersLists; j++) {
                ArrayList<Class> other = superClasses.get(j);
                boolean trouve = false;
                for (int k = 0; k < other.size() && !trouve; k++) {
                    Class cl = other.get(k);
                    if(cl.getName().equals(className)) {
                        trouve = true;
                    }
                }
                if (!trouve) testInAllOthersLists = false;
            }
            if (testInAllOthersLists) {
                plusSpecifique = first.get(i);
            }
        }
        return plusSpecifique;
    }
}
