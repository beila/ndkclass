
// ������ Ű + R: ����â ����!
// ���� ��, cmd �Է�

// ��ó��
// windows: cl.exe hello.c /P
//   linux: gcc -E hello.c -o hello.i

// ������
// windows: cl.exe hello.i /FAs /TC

#define SQR(x)		((x)*(x))

int main()
{
	int n = SQR(2);

	return 0;
}