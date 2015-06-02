
// Main.java
public class Main
{
	public static native double getCircleArea(int r);
	static { System.loadLibrary("circle"); }	// libcircle.so

	public static void main(String[] args)
	{
		System.out.println(getCircleArea(2));
		System.out.println(getCircleArea(2));
	}
}


