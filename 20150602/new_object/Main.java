public class Main {
    public static native Math newMath();
    static { System.loadLibrary("math"); }

    public static void main(String[] args) {
	Math math = newMath();
	System.out.println(math.add(1, 1));
    }
}
