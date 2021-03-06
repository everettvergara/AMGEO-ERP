/*
 *  excpt.h	Structured Exception Handling types, defines and routines
 *
 *  Copyright by WATCOM International Corp. 1988-1996.  All rights reserved.
 */
#ifndef _EXCPT_H_INCLUDED
#define _EXCPT_H_INCLUDED
#define _INC_EXCPT
#ifdef __cplusplus
extern "C" {
#endif


/*
 * Exception disposition return values.
 */
typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;


/*
 * Prototype for SEH support function.
 */
struct _EXCEPTION_RECORD;
struct _CONTEXT;

EXCEPTION_DISPOSITION __cdecl _except_handler (
	struct _EXCEPTION_RECORD *ExceptionRecord,
	void * EstablisherFrame,
	struct _CONTEXT *ContextRecord,
	void * DispatcherContext
	);

/*
 * Keywords and intrinsics for SEH
 */
#define __try		_try
#define __except	_except
#define __finally	_finally
#define __leave		_leave
#define GetExceptionCode		_exception_code
#define exception_code			_exception_code
#define GetExceptionInformation 	(struct _EXCEPTION_POINTERS *)_exception_info
#define exception_info			(struct _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination		_abnormal_termination
#define abnormal_termination		_abnormal_termination

unsigned long __cdecl _exception_code(void);
void *	      __cdecl _exception_info(void);
int	      __cdecl _abnormal_termination(void);


/*
 * Legal values for expression in except().
 */
#define EXCEPTION_EXECUTE_HANDLER	 1
#define EXCEPTION_CONTINUE_SEARCH	 0
#define EXCEPTION_CONTINUE_EXECUTION	-1


#ifdef __cplusplus
};
#endif
#endif
