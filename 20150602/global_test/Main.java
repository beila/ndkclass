public class Main {
    static native double getCircleArea(int r);
    static { System.loadLibrary("circle"); }

    static public void main(String[] args) {
	System.out.println("area = " + getCircleArea(5));
	System.out.println("area = " + getCircleArea(6));
    }
}
