#ifndef SCRATCH_STDARG_H_
#define SCRATCH_STDARG_H_


typedef void * va_args;

#define va_start(v1, v2) v1 = ((void *) &v2)
#define va_next(v1, type) *((type *)(v1 += sizeof(type)))
#define va_end(v1) v1 = 0

#endif
