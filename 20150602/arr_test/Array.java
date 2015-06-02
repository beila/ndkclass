
// Array.java
// terminal: ctrl + alt + t

public class Array
{
	static { System.loadLibrary("array"); }	// libarray.so
	public static native void printIntArray(int[] arr);

	public static void main(String[] args)
	{
		int[] arr = { 1,2,3,4,5 };	// == int[] arr = new int[5];
		printIntArray(arr);
	}
}
