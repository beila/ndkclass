
// Array.java

public class Array
{
	static { System.loadLibrary("array"); } 	// libarray.so

	public static native void printDoubleArray(double[] arr);
	
	public static void main(String[] args)
	{
		double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
		printDoubleArray(arr);
	}
}
