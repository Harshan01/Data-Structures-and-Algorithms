#include <stdio.h>

int bits;

void p(int n);
void g();
void h();
void d();

int main()
{
	printf("%u", &bits);
	int a = 10, h = 10e9, m;
	while (a <= h) {
		m = a + (h-a)/2;
		p(m);
		a = m + 1;
	}
	return 0;
}

void p(int n) {
	if (!n)
		return;
	printf("%u", &n);
	p(n-1);
}

void g() {
	int goa;
	printf("%u", &goa);
}

void h() {
	int hyd;
	printf("%u", &hyd);
}

void d() {
	int dub;
	printf("%u", &dub);
}
