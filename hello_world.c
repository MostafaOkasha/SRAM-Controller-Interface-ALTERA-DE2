#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include <unistd.h>
#include <string.h>
///////////////////////////////
typedef enum { false, true } bool;
bool test = true;
///////////////////////////////
int i,j,k;
///////////////////////////////
char readchar[5];
char writechar[5]  = {'0', '1', '2', '3', '4'};
char *initialchar = (char *) SRAM_CONTROLLER_0_BASE; //++ increase 1 byte
///////////////////////////////
int readint[5];
int writeint[5] = {5, 10, 15, 20, 25};
int *initialint = (int *) SRAM_CONTROLLER_0_BASE; //++ increase 1 byte   //4 bytes //++ increase by 4 bytes //function sizeof to get sizeof integer to get the size
/////////////////////////
short readshort[5];
short writeshort[5] = {11, 22, 33, 44, 55};
short *initialshort = (short *) SRAM_CONTROLLER_0_BASE; //2 bytes ++increases by 2 bytes
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//char writechar[5]  = {'0', '1', '2', '3', '4'};
void writeReadChars(){
	//Writing component
for(i = 0; i < 5; i++){
	*initialchar = writechar[i];    //write a character into the memory location
	//usleep(1000*1000);
	printf("Value being written: %c \n", *initialchar); //Print a
	printf(" Memory location incremented to: %x\n", initialchar); //the memorylocation was changed to?
	//usleep(1000*1000);
	initialchar++;
}
//Reading component
//usleep(1000*1000);
initialchar--;
for(i = 4; i > -1; i--){
		readchar[i] = *initialchar;
		//usleep(1000*1000);
		printf("Value being read: %c \n", *initialchar); //Print a
		printf(" Memory location decremented to: %x\n", initialchar); //the memorylocation was changed to?
		initialchar--;
		//usleep(1000*1000);
		if ( readchar[i] != writechar[i] ){
			printf("Error in reading/wri1ting characters %i",i);
		}
	}
}
//short writeshort[5] = {15, 20, 35, 45, 55};
void writeReadShorts(){
	//Writing component
for(i = 0; i < 5; i++){
	*initialshort = writeshort[i];    //write a character into the memory location
//	usleep(1000*1000);
	printf("Value being written: %i \n", *initialshort); //Print a
	printf(" Memory location incremented to: %x\n", initialshort); //the memorylocation was changed to?
//	usleep(1000*1000);
	initialshort++;
}
//Reading component
//usleep(1000*1000);
initialshort--;
for(i = 4; i > -1; i--){
		readshort[i] = *initialshort;
		//usleep(1000*1000);
		printf("Value being read: %i \n", *initialshort); //Print a
		printf(" Memory location decremented to: %x\n", initialshort); //the memorylocation was changed to?
		//usleep(1000*1000);
		initialshort--;
		if ( readshort[i] != writeshort[i] ){
			printf("Error in reading/writing characters %i",i);
		}
	}
}
//int writeint[5] = {5, 10, 15, 20, 25};
void writeReadInt(){
	//Writing component
for(i = 0; i < 5; i++){
	*initialint = writeint[i];    //write a character into the memory location
	//usleep(1000*1000);
	printf("Value being written: %i \n", *initialint); //Print a
	printf(" Memory location incremented to: %x\n", initialint); //the memorylocation was changed to?
	//usleep(1000*1000);
	initialint++;
}
//Reading component
//usleep(1000*1000);
initialint--;
for(i = 4; i > -1; i--){
	//usleep(1000*1000);
		readint[i] = *initialint;
		printf("Value being read: %i \n", *initialint); //Print a
		printf(" Memory location decremented to: %x\n", initialint); //the memorylocation was changed to?
		//usleep(1000*1000);
		initialint--;
		if ( readint[i] != writeint[i] ){
			printf("Error in reading/writing characters %i",i);
		}
	}
}

int main()
{
    printf("Hello from Group 13 MT3TB4-2017!\n");
while(1){
	//writeReadChars();
	//usleep(1000*1000);
	//writeReadShorts();
	//usleep(1000*1000);
	writeReadInt();
	//usleep(1000*1000);
}
return 0;
}



/*
printf("Value written was: %c \n", *initialmem); //Print a

printf(" Memory location incremented to: %x\n", initialmem); //the memorylocation was changed to?
printf("2nd Value stored is: %c \n", *initialmem); //Print nothing?

printf(" Memory location is now: %x\n", initialmem);
printf("Value stored is: %c \n", *initialmem); //Print nothing?
usleep(1000*1000);
*initialmem = 'a';    //write a character into the memory location
printf("Value written was: %c \n", *initialmem); //Print a
initialmem++;
printf(" Memory location incremented to: %x\n", initialmem); //the memorylocation was changed to?
printf("2nd Value stored is: %c \n", *initialmem); //Print nothing?
*initialmem = 'b'; //dont loop more than 127. or you'll get a - value
usleep(1000*1000);
printf("2nd Value written was: %c \n", *initialmem); //Print b
*/
























		//with short


		//usleep(1000*1000);
	    //printf("Fmemory location is : 0x%x \n", initialmem); //THE RIGHT WAY TO VIEW
	    //*(char *)SRAM_CONTROLLER_0_BASE = "a";  // store int value 10 at address base
		/*
		initialmem = "ab";
		usleep(1000*1000);
		printf("First value written is: %c%c \n", *(initialmem[0]),*(initialmem[1]));
		first_byte = initialmem[0];
		second_byte = initialmem[1];
		printf("LOWER value written is: %c \n", first_byte);
		printf("LOWER value written is: %c \n", second_byte);



	    initialmem = "mc";
		//   ****initialmem = 'm';
		usleep(1000*1000);
		printf("Second value written is: %c \n", *(initialmem));
		first_byte = initialmem[0];
		second_byte = initialmem[1];
		printf("LOWER value written is: %c \n", first_byte);
		printf("LOWER value written is: %c \n", second_byte);
		usleep(1000*1000);
*/
		//printf("content at %i is %i and %i\n", initialmem, *initialmem, &initialmem);


		//*initialmem=0xFF;
		//printf(" Memory location now: %x\n", initialmem);
		//printf(" Character written in it: %c\n", *initialmem);
		//usleep(1000*1000);
		//initialmem++;
		//++(*p++);
		//*(char *)initialmem = 'b';    //write a character into the memory location
		//usleep(1000*1000);
		//printf(" Memory location now: %x\n", initialmem);
		//printf(" Character written in it: %c\n", *initialmem);
		//usleep(2000*2000);
		//initialmem++;
	//	test = false;

	//}
		// if ( mypointer == NULL){
		//	 printf("Error: Out of Memory \n");
		//	 exit(1);
		//}

		//*initialmem=0xFF;
		//usleep(1000*1000);
		//*initialmem=0x00;
		//usleep(1000*1000);

		//printf("writing %x\n", i);
	//	printf("reading %x = %x\n", i,temp2[i]);

		//volatile char * SW =(char *) SWITCHES_BASE;
		//char * LEDs=(char *) LEDS_BASE;
		//*LEDs=*SW;



//
//	for (i = 0; i < 9; i++) {
	//	printf("%c\n", *(mem_space + i));
	//}
/*
	int i;
	for (i = 0; i < 5; i++) {
		mem_space + 2*i = i;
	}
	for (i = 0; i < 5; i++) {
		printf("%i\n", *(mem_space+2*i));
	}
	*/

//	mem_space = 5;
//	mem_space = SRAM_CONTROLLER_0_BASE + 2;
//	mem_space = 10;
//
//	printf("%i\n", *(SRAM_CONTROLLER_0_BASE));
//	printf("%i\n", *(SRAM_CONTROLLER_0_BASE + 1));

//char * LEDs=(char *)LEDS_BASE;
//printf("Hello from Group 13 MT3TB4-2017!\n");
//while(1){
	//*LEDs=0xFF;
	//usleep(1000*1000);
	//*LEDs=0x00;
	//usleep(1000*1000);

	//volatile char * SW =(char *) SWITCHES_BASE;
	//char * LEDs=(char *) LEDS_BASE;
	//*LEDs=*SW;

//}

/*
 * #include <stdio.h>

#include "system.h"

#include "altera_avalon_pio_regs.h"

//Is this define statement correct? How do we manually fit it the memory?

#define SRAM_CONTROLLER_0_BASE


void writeReadChars(){

	char dataToWrite[6] = "a2DxY";

	char dataToRead[6] = "a2DxY";

	int i = 0;
	//Writing component

for(i = 0; i<sizeof(dataToWrite); i++){

SRAM_CONTROLLER_0_BASE[i] = dataToWrite[i];

}


//Reading component


for(i = 0; i<sizeof(dataToRead); i++){

		if (SRAM_CONTROLLER_0_BASE[i] != dataToRead[i]){

			printf("Error reading the proper characters");

		}
	}

	//Sanitize the SRAM_CONTROLLER address


}



void writeReadShortWords(){

short dataToWrite[6] = {23, 24, 25, 26, 27};
hort dataToRead[6] = {23, 24, 25, 26, 27};

int i = 0;
	//Writing component
for(i = 0; i<sizeof(dataToWrite); i++){

		SRAM_CONTROLLER_0_BASE[i] = dataToWrite[i];

	}
	//Reading component

for(i = 0; i<sizeof(dataToRead); i++){

		if (SRAM_CONTROLLER_0_BASE[i] != dataToRead[i]){

			printf("Error reading the proper Short integers");

		}

}

	//Sanitize the SRAM_CONTROLLER address

}



void writeReadInt(){

	int dataToWrite[6] = {104, 1118, 32, 54, 31000};

	int dataToRead[6] = {104, 1118, 32, 54, 31000};

	int i = 0;
	//Writing component

	for(i = 0; i<sizeof(dataToWrite); i++){

		SRAM_CONTROLLER_0_BASE[i] = dataToWrite[i];

}
	//Reading component

for(i = 0; i<sizeof(dataToRead); i++){

		if (SRAM_CONTROLLER_0_BASE[i] != dataToRead[i]){

			printf("Error reading the proper Integers");

		}

	}


	//Sanitize the SRAM_Controller address

}


void main()
{

	writeReadChars();

	writeReadShortWords();

	writeReadInt();

}
*/
