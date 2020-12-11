//Code by Leon Mach
//Student of the Warsaw University of Technology
//Any copying of this code without consent of the owner is a criminal offence
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node {
	int value;
	int no;
	struct node *next;
};

int Digits(int x);

void test(int x, int *c, int order, struct node *Last);

int Fill(int n, int x);


/*struct node_Circular {
	int value;
	char tag;
	int *next;

};*/

int main() {
	int i, j, l, m, count, order;
	struct node *p, *first, *last, *previous;
	printf("Please enter the lower and upper bound for Potychkov numbers: \n");
	scanf("%d, %d", &l, &m);
	count = 0;
	order = Digits(m);	//Order of the number i.e. number of digits
	previous = NULL;
	for(i = 0; i <= order; i++) //Load and initialise the dynamic regular linked list
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->next = previous;
		p->value = 0;
		p->no = i;
		previous = p;
		if(p->no == 0) first = p;
		if(p->no == order) last = p;
	};
	for (j = l; j <= m; j++) test(j, &count, order, last);
	printf("%d\n", count);
	//printf("There are %d Potychkov numbers in the given interval.", count);
	free(p);
	return 0;
};

int Digits(int x) {
	return (floor(log10(x)));
};

int Fill(int n, int x) {
	int result;
	result = x % (int)pow(10, n+1);
	result = floor(result/(int)pow(10, n));
	return result;
};

void test(int x, int *c, int order, struct node *Last) {
	struct node *p = Last;
	int i = order;
	int digits; 
	digits = Digits(x);
	int nonZeroDigits = 0;
	int divisors = 0;
	while(p != NULL) //Filling the linked list 
	{
		p->value = Fill(i--, x);
		p = p->next;
	};
	p = Last;
	while(p != NULL) 
	{
		if((p->no) <= digits && p->value != 0) (nonZeroDigits)++;
		p = p->next;
	};
	p = Last;
	if(nonZeroDigits - digits == 1) while(p != NULL) {
		if((p->no <= digits) && ((x % (p->value)) == 0)) divisors++;
		p = p->next;
	}
	if(divisors == nonZeroDigits) {
		(*c)++;
		//printf("%d\n", x);
	};
};