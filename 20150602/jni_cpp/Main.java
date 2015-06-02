public class Main {
    public static native String getHelloWorld();

    static { System.loadLibrary("hello"); }

    public static void main(String[] args) {
	System.out.println(getHelloWorld());
    }
}
