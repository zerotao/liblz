#ifndef __LZ_INTERNAL_H__
#define __LZ_INTERNAL_H__

#ifdef HAS_VISIBILITY_HIDDEN
#define __visible __attribute__((visibility("default")))
#define EXPORT_SYMBOL(x) typeof(x)(x)__visible
#else
#define EXPORT_SYMBOL(n)
#endif

#if defined __GNUC__ || defined __llvm__
#define lz_likely(x)     __builtin_expect(!!(x), 1)
#define lz_unlikely(x)   __builtin_expect(!!(x), 0)
#else
#define lz_likely(x)     (x)
#define lz_unlikely(x)   (x)
#endif

#ifndef TAILQ_FOREACH_SAFE
#define TAILQ_FOREACH_SAFE(var, head, field, tvar)        \
    for ((var) = TAILQ_FIRST((head));                     \
         (var) && ((tvar) = TAILQ_NEXT((var), field), 1); \
         (var) = (tvar))
#endif

#ifndef SLIST_FOREACH_SAFE
#define SLIST_FOREACH_SAFE(var, head, field, tvar)        \
    for ((var) = SLIST_FIRST((head));                     \
         (var) && ((tvar) = SLIST_NEXT((var), field), 1); \
         (var) = (tvar))
#endif

#ifndef SLIST_REMOVE
#define SLIST_REMOVE(head, elm, type, field) do {             \
        if (SLIST_FIRST((head)) == (elm)) {                   \
            SLIST_REMOVE_HEAD((head), field);                 \
        }else {                                               \
            struct type * curelm = SLIST_FIRST((head));       \
            while (SLIST_NEXT(curelm, field) != (elm)) {      \
                curelm = SLIST_NEXT(curelm, field);           \
            }                                                 \
            SLIST_NEXT(curelm, field) =                       \
                SLIST_NEXT(SLIST_NEXT(curelm, field), field); \
        }                                                     \
} while (0)
#endif

#endif

