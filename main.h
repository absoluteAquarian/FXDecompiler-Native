#ifndef FXDECOMPILER_MAIN_H_
#define FXDECOMPILER_MAIN_H_

#include <errhandlingapi.h>
#include <intrin.h>
#include <locale.h>
#include <processthreadsapi.h>
#include <stdlib.h>
#include <string.h>
#include <winnt.h>

#define EXPORT __declspec(dllexport)

EXPORT void                          o_fastfail(unsigned int code);
EXPORT void                          o_free(void *ptr);
EXPORT char                         *o_getenv(const char *name);
EXPORT BOOL                          o_IsProcessorFeaturePresent(DWORD ProcessorFeature);
EXPORT void                         *o_malloc(size_t size);
EXPORT void                          o_memcpy(void *dest, const void *src, size_t n);
EXPORT void                          o_RtlCaptureContext(PCONTEXT ContextRecord);
EXPORT PRUNTIME_FUNCTION             o_RtlLookupFunctionEntry(
	DWORD64               ControlPc,
	PDWORD64              ImageBase,
	PUNWIND_HISTORY_TABLE HistoryTable
);
EXPORT PEXCEPTION_ROUTINE            o_RtlVirtualUnwind(
	DWORD                          HandlerType,
	DWORD64                        ImageBase,
	DWORD64                        ControlPc,
	PRUNTIME_FUNCTION              FunctionEntry,
	PCONTEXT                       ContextRecord,
	PVOID                          HandlerData,
	PDWORD64                       EstablisherFrame,
	PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
);
EXPORT char                         *o_setlocale(int category, const char *locale);
EXPORT LPTOP_LEVEL_EXCEPTION_FILTER  o_SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
EXPORT BOOL                          o_TerminateProcess(HANDLE hProcess, UINT uExitCode);
EXPORT LONG                          o_UnhandledExceptionFilter(PEXCEPTION_POINTERS ExceptionInfo);

#endif // FXDECOMPILER_MAIN_H_