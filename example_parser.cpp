#include <stdio.h>
#include <assert.h>


int get_P();

const char* s = NULL;
int p = 0;

int get_N()
{
	int val = 0;

	int old_p = p;



	while (s[p] >= '0' && s[p] <= '9')
	{
		printf("func %s get value %c\n", __func__, s[p]);
		val = val * 10 +  s[p] - '0';
		p++;
	}
	assert(p > old_p);
	return val;
}


int get_T()
{
	int val1 = get_P();
	printf("after get_n\n");
	while((s[p] == '*') || (s[p] == '/'))
	{
		char op = s[p];
		p++;
		int val2 = get_P();

		printf("func %s get value %c\n", __func__, s[p]);		

		switch(op)
		{
			case '*': 
				{
					val1 *= val2; //todo -wimplicit-fallthrough
					break;
				}

			case '/': 
				{
					val1 /= val2;
					break;
				}
			default: 
				{
					printf("syntax error in func %s", __func__);
					break;
				} 
		}
	}

	return val1;
}





int get_E()
{
	printf("before get T 1\n");
	int val1 = get_T();
	printf("after get T 1\n");
	while((s[p] == '+') || (s[p] == '-'))
	{
		char op = s[p];
		p++;
		int val2 = get_T();
		printf("func %s op: %c\n", __func__, op);
		switch(op)
		{
			case '+': 
				{
					val1 += val2; //todo -wimplicit-fallthrough
					break;
				}

			case '-': 
				{
					val1 -= val2;
					break;
				}
			default: 
				{
					printf("syntax error in func %s", __func__);
					break;
				} 
		}
	}

	return val1;
}




int get_G(const char* str)
{
	s = str;
	p = 0;
	printf("before get_e\n");
	int val = get_E();
	printf("after get_e\n");

	if (s[p] != '\0')
	{
		printf("syntax error in func %s", __func__);
	}

	return val;
}


int get_P()
{
	int val = 0;
	if (s[p] == '(')
	{
		p++;
		val = get_E();

		if (s[p] == ')')
		{
			printf("syntax error in funct get_p\n");
		}

		p++;
	}
	else
	{
		val = get_N();
	}		

	return val;
}

int main()
{
	char str[1000] = {};
	scanf("%s", str);

	printf("%s", str);

	int b = get_G(str);

	printf("after get_g");
	printf("%d", b);

	printf("%d", get_G(str));

	return 0;
}