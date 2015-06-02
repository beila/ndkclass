
// Array.java

public class Array
{
	static { System.loadLibrary("array"); }	// libarray.so
	public static native void print2DIntArray(int[][] arr);

	public static void main(String[] args)
	{
		int[][] arr = { {1,2,3}, {4,5,6} };	// int[][] arr = new int[2][3];
		print2DIntArray(arr);
	}
}

