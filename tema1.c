#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct adress {
	unsigned int a, b, c, d;
};



struct network{
	unsigned int a, b, c, d, e;
};

void read_adress(int *a, int *b, int *c, int *d) {
	scanf("%d.%d.%d.%d", a, b, c, d);
};
void read_network(int *a, int *b, int *c, int *d, int *e){
	scanf("%d.%d.%d.%d/%d", a, b, c, d, e);
}
struct adress task1(int MSK_2) {
	struct adress result;
	unsigned short byte_1 = 0, byte_2 = 0 , byte_3 = 0, byte_4 = 0;
	unsigned short aux = 1, aux2 = 0; // aux  and aux2 are used for logical operarions on bits
	int rest, completed;
	rest = MSK_2 % 8;
	completed = MSK_2 / 8;
	if(completed == 1) {
		byte_1 = 255;
		for (int i = 0; i < rest; ++i) {
			aux2 = 0;
			aux2 = aux2 | aux;
			aux2 = aux2 << (7 - i);
			byte_2 = byte_2 | aux2;
		}
	} else if (completed == 2) {
		byte_1 = 255;
		byte_2 = 255;
		for (int i = 0; i < rest; ++i) {
			aux2 = 0;
			aux2 = aux2 | aux;
			aux2 = aux2 << (7 - i);
			byte_3 = byte_3 | aux2;
		}
	} else if (completed == 3) {
		byte_1 = 255;
		byte_2 = 255;
		byte_3 = 255;
		for (int i = 0; i < rest; ++i) {
			aux2 = 0;
			aux2 = aux2 | aux;
			aux2 = aux2 << (7 - i);
			byte_4 = byte_4 | aux2;
		}
	} else if (completed == 4) {
		byte_1 = 255;
		byte_2 = 255;
		byte_3 = 255;
		byte_4 = 255;
	}
	result.a = byte_1;
	result.b = byte_2;
	result.c = byte_3;
	result.d = byte_4;
	return result;
}
void print_task1(struct adress mask) {
	printf("-1 %d.%d.%d.%d\n", mask.a, mask.b, mask.c, mask.d);
}
int turnOctal(unsigned int number) {
	int octalNumber = 0, i = 1;
    while(number != 0) {
        octalNumber += (number % 8) * i;
        number /= 8;
        i *= 10;
    } 
    return octalNumber;
}
int turnBinar(unsigned int number) {
	int binarNumber = 0, i = 1;
	while(number != 0) {
		binarNumber += (number % 2) * i;
		number /= 2; 
		i *= 10;
	}
	return binarNumber;
}

void task2(struct adress MSK_1) {
	printf("-2 %d.%d.%d.%d ", turnOctal(MSK_1.a), turnOctal(MSK_1.b), turnOctal(MSK_1.c), turnOctal(MSK_1.d));
	printf("%x.%x.%x.%X\n", MSK_1.a, MSK_1.b, MSK_1.c, MSK_1.d);
}

struct adress task3(struct adress IP, struct adress mask) {
	struct adress result;
	result.a = IP.a & mask.a;
	result.b = IP.b & mask.b;
	result.c = IP.c & mask.c;
	result.d = IP.d & mask.d;
	return result;
}
void print_task3(struct adress IP, struct adress mask) {
	printf("-3 %d.%d.%d.%d\n", IP.a & mask.a, IP.b & mask.b, IP.c & mask.c, IP.d & mask.d);
}
void task4(struct adress IP, struct adress mask) {
	printf("-4 %d.%d.%d.%d\n", IP.a | 255 - mask.a, IP.b | 255 - mask.b, IP.c | 255 - mask.c, IP.d | 255 - mask.d);
}
void task5(struct adress adress_1, struct adress adress_2) {
	if( adress_1.a == adress_2.a && adress_1.b == adress_2.b && adress_1.c == adress_2.c && adress_1.d == adress_2.d) {
		printf("-5 DA\n");
	} else {
		printf("-5 NU\n");
	}
}
bool task6_checker(unsigned int number) {
	unsigned int usableBit, usableBits[8], movableBit = 1, compare = 0;
	int i = 0;
	movableBit = movableBit << 7;
	if(number == 255 || number == 0) {
		return 1;
	}
	while(usableBit != 0) {
		usableBit = number & movableBit;
		usableBits[i] = usableBit;
		movableBit = movableBit >> 1;
		i++;
	}
	for (int j = 0; j < i; j++) {
		compare += usableBits[j];
	}
	if(compare == number){
		return 1;
	} 
	return 0;
}
bool task6(struct adress mask) {
	if(task6_checker(mask.a) && task6_checker(mask.b) && task6_checker(mask.c) && task6_checker(mask.d)){
		printf("-6 DA\n");
		return 1;
	}
	printf("-6 NU\n");
	return 0;
}
unsigned int task7_corrector(unsigned int number) {
	unsigned int result = 0, usableBit, usableBits[8], movableBit = 1;
	int i = 0;
	movableBit = movableBit << 7;
	while(usableBit != 0){
		usableBit = number & movableBit;
		usableBits[i] = usableBit;
		movableBit = movableBit >> 1;
		i++;
	}
	for (int j = 0; j < i; j++){
		result = result + usableBits[j];
	}
	return result;
}
void task7(struct adress mask,  bool checker) {
	unsigned int corected;
	if(checker == 1) {
		printf("-7 %d.%d.%d.%d\n", mask.a, mask.b, mask.c, mask.d);
	} else {
		if(mask.a != 255 && mask.a != 0) {
			corected = task7_corrector(mask.a);
			printf("-7 %d.%d.%d.%d\n", corected, mask.b, mask.c, mask.d);
		} else if(mask.b != 255 && mask.b != 0) {
				corected = task7_corrector(mask.b);
				printf("-7 %d.%d.%d.%d\n",mask.a, corected, mask.c, mask.d);
			} else if(mask.c != 255 && mask.c != 0) {
				corected = task7_corrector(mask.c);
				printf("-7 %d.%d.%d.%d\n",mask.a, mask.b, corected, mask.d);
				} else if(mask.d != 255 && mask.d != 0) {
						corected = task7_corrector(mask.d);
						printf("-7 %d.%d.%d.%d\n",mask.a, mask.b, mask.c,corected);
					}
	}
}
void task8(struct adress mask) {
	printf("-8 %08d.%08d.%08d.%08d\n", turnBinar(mask.a), turnBinar(mask.b), turnBinar(mask.c), turnBinar(mask.d));
}
void task9(struct adress IP, struct network networks[], int count) {
	int validNetworks[count], j = 0;
	for (int i = 0; i < count; i++) {
		struct adress check = task3(IP, task1(networks[i].e));
		struct adress my_ip;
		my_ip.a = networks[i].a;
		my_ip.b = networks[i].b;
		my_ip.c = networks[i].c;
		my_ip.d = networks[i].d;
		struct adress nmask = task3(my_ip, task1(networks[i].e));
		if(check.a == nmask.a && check.b == nmask.b && check.c == nmask.c && check.d == nmask.d) {
			validNetworks[j] = i;
			j++;
		}
	}
	printf("-9 ");
	for (int k = 0; k < j; k++) {
		printf("%d ", validNetworks[k]);
	}	
}
int main() {
	// FILE *in, *out;
	// in = fopen("test.txt", "r");
	// FILE *out;
	// out = fopen("output.txt", "w");
	struct adress MSK_1, IP_1, IP_2, mask, network_IP_1, network_IP_2;
	int MSK_2, N;
	bool task6_checker;
	int number_lines;
	scanf("%d", &number_lines);
	for (int i = 0; i < number_lines; ++i) {
		read_adress(&MSK_1.a, &MSK_1.b, &MSK_1.c, &MSK_1.d);
		scanf("%d", &MSK_2);
		read_adress(&IP_1.a, &IP_1.b, &IP_1.c, &IP_1.d);
		read_adress(&IP_2.a, &IP_2.b, &IP_2.c, &IP_2.d);
		scanf("%d", &N);
		struct network networks[N];
		for (int j = 0; j < N; ++j) {
			read_network(&networks[j].a, &networks[j].b, &networks[j].c, &networks[j].d, &networks[j].e);
		}
		// printf ("citirea %i\n", i + 1);
	
	printf("%d\n", i + 1);
	printf("-0 %d.%d.%d.%d/%d\n", IP_1.a, IP_1.b, IP_1.c, IP_1.d, MSK_2); // printf task 1
	mask = task1(MSK_2); // mask = result
	print_task1(mask);
	task2(MSK_1);
	network_IP_1 = task3(IP_1, mask);
	network_IP_2 = task3(IP_2, mask);
	print_task3(IP_1, mask);
	task4(IP_1, mask);
	task5(network_IP_1, network_IP_2);
	task6_checker = task6(MSK_1);
	task7(MSK_1, task6_checker);
	task8(IP_1);
	task9(IP_2, networks, N);
	printf("\n");
	}
	//fclose(in);
	//fclose(out);
	return 0;
}
