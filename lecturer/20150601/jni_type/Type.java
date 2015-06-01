
// Type.java

public class Type
{
	// native mtehod
	public static native void printBoolean(boolean a);
	public static native void printByte(byte a);
	public static native void printChar(char a);
	public static native void printShort(short a);
	public static native void printInt(int a);
	public static native void printLong(long a);
	public static native void printFloat(float a);
	public static native void printDouble(double a);

	// load library
	static { System.loadLibrary("type"); }	// libtype.so

	public static void main(String[] args)
	{
		printBoolean(true);	// 1
		printByte((byte)1);	// 1
		printChar('A');		// %c = A, %d = 65
		printShort((short)1);	// 1
		printInt(1);			// 1
		printLong((long)1);		// 1
		printFloat((float)3.14);	// 3.14
		printDouble(3.14);			// 3.14
	}
}
