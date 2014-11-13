#ifndef __LZ_INTERNAL_H__
#define __LZ_INTERNAL_H__

#ifdef HAS_VISIBILITY_HIDDEN
#define __visible   __attribute__((visibility("default")))
#define EXPORT_SYMBOL(x)      typeof(x)(x)__visible
#else
#define EXPORT_SYMBOL(n)
#endif

#endif

