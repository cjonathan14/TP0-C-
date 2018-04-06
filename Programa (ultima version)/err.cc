#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "err.h"

using namespace std;

void handle_err(status_t st)
{
bool screen=true; //esta variable determina si es que se presenta por pantalla el error
char msg[ERROR_MSG_STD_LENGTH],*msg_time;
ofstream outfile;
time_t rawtime;
struct tm * timeinfo;


if(st!=OK)
{	
	outfile.open(ERROR_LOG_FILE_NAME,ios::app);

	if(st==ERROR_OUT_OF_MEMORY)
		strcpy(msg,MSG_ERROR_OUT_OF_MEMORY);
	else if(st==ERROR_INVALID_INPUT_FILE)
		strcpy(msg,MSG_ERROR_INVALID_INPUT_FILE);
	else if(st==ERROR_INVALID_OUTPUT_FILE)
		strcpy(msg,MSG_ERROR_INVALID_OUTPUT_FILE);
	else if(st==ERROR_INVALID_INPUT_VECTOR)
		{strcpy(msg,MSG_ERROR_INVALID_INPUT_VECTOR);screen=false;}
	else if(st==ERROR_INVALID_OUTPUT_VECTOR)
		{strcpy(msg,MSG_ERROR_INVALID_OUTPUT_VECTOR);screen=false;}
	else if(st==ERROR_WRONG_NUMBER_OF_ARGUMENTS)
		strcpy(msg,MSG_ERROR_WRONG_NUMBER_OF_ARGUMENTS);
	else if(st==ERROR_PROGRAM_INVOCATION)
		strcpy(msg,MSG_ERROR_PROGRAM_INVOCATION);
	else if(st==ERROR_CORRUPT_LINE)
		strcpy(msg,MSG_ERROR_CORRUPT_LINE);


	
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	msg_time=asctime(timeinfo);

	if(screen)
		cout<<msg<<endl;

	outfile<<msg<<" - "<<msg_time<<endl;
}
outfile.close();

}
