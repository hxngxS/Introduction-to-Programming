#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	int op_st[100],			/* operator stack */
		op_opr_size[100],		/* operand stack size at the time of pushing the operator */
		op_sp = -1;			/* operator stack position */

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case '+': case '-': case '*': case '/':
			op_st[++op_sp] = type;
			op_opr_size[op_sp] = size();
			break;
			/* 읽어들인 type을 연산자 스택에 넣고, 해당 시점에서 현재 스택에 있는 피연산자 개수를 op_opr_size배열에 저장 */
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case NUMBER:
			push(atof(s));
			while (op_sp >= 0 && size() - op_opr_size[op_sp] == 2	/* 연산자 존재 && 피연산자 2개 준비되어있는지 확인 */) {
				int op = op_st[op_sp--]; /* 연산자 스택에서 연산자 꺼내오기 */
					switch (op) {
					case '+':
						push(pop() + pop());
						break;
					case '*':
						push(pop() * pop());
						break;
					case '-':
						op2 = pop();
						push(pop() - op2);
						break;
					case '/':
						op2 = pop();
						if (op2 != 0.0)
							push(pop() / op2);
						else
							printf("error: zero divisor\n");
						break;
					}
			}
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}