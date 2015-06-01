
// 윈도우 키 + R: 실행창 실행!
// 실행 후, cmd 입력

// 전처리
// windows: cl.exe hello.c /P
//   linux: gcc -E hello.c -o hello.i

// 컴파일
// windows: cl.exe hello.i /FAs /TC

#define SQR(x)		((x)*(x))

int main()
{
	int n = SQR(2);

	return 0;
}