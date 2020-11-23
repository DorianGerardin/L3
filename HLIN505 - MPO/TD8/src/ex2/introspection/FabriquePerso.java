package ex2.introspection;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Scanner;

public class FabriquePerso {

    public static Scanner input = new Scanner(System.in);

    public static Personnage newEmptyInstance(String className) throws Exception {

        Class<?> c = Class.forName(className);
        //Personnage np = (Personnage) c.newInstance();
        Constructor constructor = c.getConstructor();
        Personnage np = (Personnage) constructor.newInstance();
        return np;
    }

    public static Personnage initInstance(Personnage p) throws Exception {
        Field[] fields = getAllFields(p);
        System.out.println("Cet object possède " + fields.length + " attributs");
        for(Field f : fields) {
            if (f.getType().isPrimitive() || f.getType().getName().endsWith("String")) {
                f.setAccessible(true);
                Class fType = f.getType();
                String f_name = f.getName();
                System.out.println("Entrez une valeur pour l'attribut " + f_name + " de type " + fType + " : ");
                String value = input.nextLine();
                if (fType == int.class) {
                    Integer vType = Integer.parseInt(value);
                    f.set(p, vType);
                } else if (fType == boolean.class) {
                    Boolean vType = Boolean.parseBoolean(value);
                    f.set(p, vType);
                } else {
                    f.set(p, value);
                }
            }
        }
        return p;
    }

    public static Personnage newInstance(String className) throws Exception {
        Personnage np = newEmptyInstance(className);
        initInstance(np);
        return np;
    }

    public static Field[] getAllFields(Object o) {
        ArrayList<Class> sc = new ArrayList<>();
        Class c = o.getClass();

        while(c != null) {
            sc.add(c);
            c = c.getSuperclass();
        }

        ArrayList<Field> fda = new ArrayList<>();

        for(Class cc : sc) {
            Field[] fdt = cc.getDeclaredFields();
            for (int i = 0; i < fdt.length; i++) {
                fda.add(fdt[i]);
            }
        }

        Field[] result = new Field[fda.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = fda.get(i);
        }
        return result;
    }

    public static void main(String[] args) throws Exception{
        System.out.println("Entrer le nom de la classe de Personnage : ");
        String className = "ex2.introspection." + input.nextLine();

        Personnage p = FabriquePerso.newInstance(className);
        System.out.println(p);
        input.close();
    }

}
