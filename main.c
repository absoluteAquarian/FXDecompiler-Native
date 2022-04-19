#include "main.h"

EXPORT char *o_setlocale(int category, const char *locale) {
	return setlocale(category, locale);
}

EXPORT void *o_malloc(size_t size) {
	return malloc(size);
}

EXPORT void o_free(void *ptr) {
	free(ptr);
}

EXPORT void o_memcpy(void *dest, const void *src, size_t n) {
	memcpy(dest, src, n);
}

EXPORT char *o_getenv(const char *name) {
	return getenv(name);
}

EXPORT void o_RtlCaptureContext(PCONTEXT ContextRecord) {
	RtlCaptureContext(ContextRecord);
}

EXPORT PRUNTIME_FUNCTION o_RtlLookupFunctionEntry(
	DWORD64               ControlPc,
	PDWORD64              ImageBase,
	PUNWIND_HISTORY_TABLE HistoryTable
) {
	return RtlLookupFunctionEntry(ControlPc, ImageBase, HistoryTable);
}

EXPORT PEXCEPTION_ROUTINE o_RtlVirtualUnwind(
	DWORD                          HandlerType,
	DWORD64                        ImageBase,
	DWORD64                        ControlPc,
	PRUNTIME_FUNCTION              FunctionEntry,
	PCONTEXT                       ContextRecord,
	PVOID                          HandlerData,
	PDWORD64                       EstablisherFrame,
	PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
) {
	return RtlVirtualUnwind(HandlerType, ImageBase, ControlPc, FunctionEntry, ContextRecord, HandlerData, EstablisherFrame, ContextPointers);
}

EXPORT BOOL o_IsProcessorFeaturePresent(DWORD ProcessorFeature) {
	return IsProcessorFeaturePresent(ProcessorFeature);
}

EXPORT void o_fastfail(unsigned int code) {
	/*
	MOV RCX,code
	INT 0x29
	*/
	__asm__(
		"int $0x29" : : "c" (code)
	);
}

EXPORT BOOL o_TerminateProcess(HANDLE hProcess, UINT uExitCode) {
	return TerminateProcess(hProcess, uExitCode);
}

EXPORT LPTOP_LEVEL_EXCEPTION_FILTER o_SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter) {
	return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}

EXPORT LONG o_UnhandledExceptionFilter(PEXCEPTION_POINTERS ExceptionInfo) {
	return UnhandledExceptionFilter(ExceptionInfo);
}