
// Array.java
// terminal: ctrl + alt + t

public class Array
{
	static { System.loadLibrary("array"); }	// libarray.so
	public static native void printDoubleArray(double[] arr);

	public static void main(String[] args)
	{
		double[] arr = { 1.1,2.2,3.3,4.4,5.5 };	// == int[] arr = new int[5];
		printDoubleArray(arr);
	}
}
