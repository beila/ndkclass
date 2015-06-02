
// Array.java

public class Array
{
	static { System.loadLibrary("array"); }	// libarray.so
	public static native int[] makeIntArray(int len);
	public static native double[] makeDoubleArray(int len);

	public static void main(String[] args)
	{
		int[] arr1 = makeIntArray(5);
		for(int i = 0; i < arr1.length; i++)
			System.out.print(arr1[i] + " ");
		System.out.println();

		//----------------------------------

		double[] arr2 = makeDoubleArray(5);
		for(int i = 0; i < arr2.length; i++)
			System.out.print(arr2[i] + " ");
		System.out.println();
	}
}
