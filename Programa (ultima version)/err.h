#ifndef ERR__H
#define ERR__H


	typedef enum status{
						ERROR_OUT_OF_MEMORY,
						ERROR_INVALID_INPUT_FILE,
						ERROR_INVALID_OUTPUT_FILE,
						ERROR_INVALID_INPUT_VECTOR,
						ERROR_INVALID_OUTPUT_VECTOR,
						ERROR_WRONG_NUMBER_OF_ARGUMENTS,
						ERROR_PROGRAM_INVOCATION,
						ERROR_CORRUPT_LINE,
						OK
                      }status_t;


void handle_err(status_t);

#define ERROR_LOG_FILE_NAME "ErrorLog.txt"

#define ERROR_MSG_STD_LENGTH 40
#define ERROR_MSG_TIME  40

#define MSG_ERROR_OUT_OF_MEMORY "Error: System ran out of memory"
#define MSG_ERROR_INVALID_INPUT_FILE "Error: Invalid input file"
#define MSG_ERROR_INVALID_OUTPUT_FILE "Error: Invalid output file"
#define MSG_ERROR_INVALID_INPUT_VECTOR "Error: Invalid input vector"
#define MSG_ERROR_INVALID_OUTPUT_VECTOR "Error: Invalid output vector"
#define MSG_ERROR_WRONG_NUMBER_OF_ARGUMENTS "Error: Wrong number of arguments"
#define MSG_ERROR_PROGRAM_INVOCATION "Error: Wrong program invocation"
#define MSG_ERROR_CORRUPT_LINE "Error: Corrupted line"

#define MSG_TIME_OF_ERROR "Time of Error: "


#endif
