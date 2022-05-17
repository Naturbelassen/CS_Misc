#include <stdio.h>

int global1;
int global2 = 981;
//HI


int fak(int x){
	int a =44;
	printf("Addr. v. a ist %p\n",&a);
//	int a_;
//	char b = 't';
//	char b_;
//	float c = 12,24;
//	float c_;
	
	if(x==0){
		return 0;
	} else if(x==1){
		return 1;
	} else {
		 return fak(x-1) * x;
	}

}


int main(void){
	int z = 32;
	int y = 9999999999999999;
//	int a = 6;
	printf("Die Fakultaet von %d lautet: %d\n",y, fak(y));
	printf("Adr. v. global1 ist %p\n",&global1);
	printf("Adr. v. global2 ist %p\n",&global2);
	printf("Adr. v. y ist %p\n",&y);
	printf("Addr z %p\n",&z);
//	printf("Adr. v. a ist %p\n",&a;
//	printf("Adr. v. a_ ist %p\n",&a_);
//	printf("Adr. v. b ist %p\n",&b);
//	printf("Adr. v. b_ ist %p\n", &b_);
//	printf("Adr. v. c ist %p\n",&c);
//	printf("Adr. v. c_ ist %p\n",&c_);  
	
	return 0;

}
