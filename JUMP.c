#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		long long N;
		scanf("%lld", &N);
		printf("%lld\n", (N*(N + 1) / 2 + 1)*(N*(N + 1) / 2 + 1) % 20130728);
	}
}