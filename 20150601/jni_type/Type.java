public class Type {
    public static native void printBoolean(boolean a);
    public static native void printByte(byte a);
    public static native void printChar(char a);
    public static native void printShort(short a);
    public static native void printInt(int a);
    public static native void printLong(long a);
    public static native void printFloat(float a);
    public static native void printDouble(double a);

    static { System.loadLibrary("type"); }

    public static void main(String[] args) {
	printBoolean(true);
	printByte((byte)1);
	printChar('A');
	printShort((short)1);
	printInt(1);
	printLong((long)1);
	printFloat((float)3.14);
	printDouble(3.14);
    }
}
