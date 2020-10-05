package ex2;

public abstract class Expression {

    public abstract float eval();

    @Override
    public boolean equals(Object obj) {
        if (! (obj instanceof Expression)) return false;
        Expression e = (Expression) obj;
        return this.eval() == e.eval();
    }
}
