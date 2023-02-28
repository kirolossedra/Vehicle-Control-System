/*/*
 ============================================================================
 Name        : Kirolos Sedra
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define Engine_ON 97
#define Engine_OFF 98

#define Traffic_R 'R';
#define Traffic_G 'G';
#define Traffic_O 'O';

char Vehicle_Speed;
char* wPointer = 0;// Wandering pointer just used to change any value in Runtime

char Traffic_L;
struct AC {
	char state;
	char temp;
}AC;
struct ETC {
	char state;
	char temp;
}ETC;
struct Engine {
	char state;
	char temp;
}Engine;
char Ctemp;
struct AC* ACpointer = &AC;
struct ETC* ETCp = &ETC;
struct Engine* Epointer = &Engine;



char Menu_Option;



void printi(int i) {
	printf("%d", i);
	fflush(stdout);
}
void printc(char c) {
	printf("%c ", c);
	fflush(stdout);

}
////void printp(* p){
////	printf("%p",p);
////	fflush(stdout);
////}
void prints(char* string) {
	puts(string);
}
//
void EngineState(char index) {

	switch (index) {
	case Engine_ON:
		prints("Engine is ON");
		break;
	case Engine_OFF:
		prints("Engine is Off");
		break;


	}
	return;
}
void TrafficLight(char color) {
	wPointer = &Vehicle_Speed;
	switch (color) {
	case 'G':

		*wPointer = 100;

		break;
	case 'O':
		*wPointer = 30;
		break;
	case 'R':
		*wPointer = 0;
		break;




	}
	return;
}
void ACkontrol(char temp) {

	if (temp < 10) {
		ACpointer->state = Engine_ON;
		ACpointer->temp = 20;

	}
	if (temp > 30) {
		ACpointer->state = Engine_ON;
		ACpointer->temp = 20;

	}
	else {
		ACpointer->state = Engine_OFF;
		ACpointer->temp = temp;
	}
	return;
}
void ETCkontrol(char temp) {


	ETCp = &ETC;
	Epointer = &Engine;
	temp = Epointer->temp;
	if (temp < 100) {
		ETCp->state = Engine_ON;
		ETCp->temp = 125;

	}
	if (temp > 150) {
		ETCp->state = Engine_ON;
		Epointer->temp = 125;

	}
	else {
		ETCp->state = Engine_OFF;
	}
	return;

}
void EngineON() {
	prints("here is the system menu");
	prints("a. Turn off the engine");
	prints("b. Set the traffic light color");
	prints("c. Set the room temperature (Temperature Sensor)");
	prints("d. Set the engine temperature (Engine Temperature Sensor)");
	scanf(" %c", &Menu_Option);
	switch (Menu_Option) {
	case 'a':
		Epointer->state = Engine_OFF;
		EngineState(Epointer->state);
		break;
	case 'b':

		scanf(" %c", &Traffic_L);
		TrafficLight(Traffic_L);
		break;
	case 'c':
		scanf(" %c", &Ctemp);
		ACkontrol(Ctemp);
		break;
	case 'd':
		scanf(" %c", &Epointer->temp);
		ETCkontrol(Epointer->temp);
		break;



	}
	return;
}
void EngineOff(void) {
	prints("What do you want to do?");
	prints("a. Turn on the vehicle engine");
	//prints("b. Turn off the vehicle engine");
	prints("b. Quit the system");
	scanf(" %c", &Epointer->state);
	if (Epointer->state == 'c') { prints("QUITING..."); return; }
	EngineState(Epointer->state);

}
//void SensorsMenu(char index){
//	switch(index){
//	case 'a':
//		EngineState = Engine_OFF;
//		break;
//	case 'b':
//
//
//
//	}
//}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	setvbuf(stderr, NULL, _IONBF, 0);
	Epointer->state = Engine_OFF;

	//
	while (1) {
		if (Epointer->state == Engine_OFF) {
			EngineOff();

		}
		if (Epointer->state == Engine_ON) {
			EngineON();
		}


		// 			if(Vehicle_Speed == 30){
		// 							if(ACpointer->state==Engine_OFF){
		// 								ACpointer->state=Engine_ON;
		// 								wPointer = &Ctemp;
		// 								*wPointer = *wPointer*(5/4)+1;
		// 							}
		// 							if(ETCp->state==Engine_OFF){
		// 								ETCp->state=Engine_ON;
		// 								wPointer = &Epointer->temp;
		// 								*wPointer = *wPointer*(5/4)+1;
		// 							}

		// 						}

		(ACpointer->state == Engine_ON) ? prints("AC is ON") : prints("AC is OFF");

		printf("Vehicle Speed is  %d \n", Vehicle_Speed);
		printf("Room Temperature is %d \n", ACpointer->temp);
		printf("Engine Temperature is %d \n", Epointer->temp);
		(ETCp->state == Engine_ON) ? prints("Engine Temperature Controller is ON") : prints("Engine Temperature Controller is OFF");



	}



}