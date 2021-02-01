package ex2.introspection;
import java.lang.annotation.*;
import java.lang.reflect.Method;

public class ExoTodo {

    public static void main(String[] args) {
        Class[] persos = {Personnage.class, PersonnageBonus.class, PersonnageInvisible.class};
        //question a
        System.out.println("Question a ");
        afficherTodos(persos);
    }

    private static void afficherTodos(Class<?>[] classes) {
        for(Class<?> c : classes) {
            Method[] methodes = c.getMethods();
            for(Method m : methodes) {
                if (m.isAnnotationPresent(Todo.class)) {
                    String m_name = m.getName();
                    System.out.println("Annotation de la méthode " + m_name + " de la classe " + c.getName());
                    Todo a = m.getAnnotation(Todo.class);
                    System.out.println("\t -Todo : " + a.kind() + ", version : " + a.version() + ", duration : " + a.duration());
                }
            }
        }
    }

    private static void affichierTodoParTache(Class[] classes, Todo.TaskKind taskKind) {
        for(Class<?> c : classes) {
            Method[] methodes = c.getMethods();
            for(Method m : methodes) {
                if (m.isAnnotationPresent(Todo.class)) {
                    Todo a = m.getAnnotation(Todo.class);
                    if (a.kind().equals(taskKind)) {
                        String m_name = m.getName();
                        System.out.println("Annotation de la méthode " + m_name + " de la classe " + c.getName());
                        System.out.println("\t -Todo : " + a.kind() + ", version : " + a.version() + ", duration : " + a.duration());
                    }
                }
            }
        }
    }

}
