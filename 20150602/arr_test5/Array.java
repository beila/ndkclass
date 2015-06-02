
// Array.java

public class Array
{
	static { System.loadLibrary("array"); }	// libarray.so
	public static native int[][] make2DIntArray(int row, int col);

	public static void main(String[] args)
	{
		int[][] arr = make2DIntArray(2, 3);
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 3; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
	}
}
