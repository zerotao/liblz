#ifndef __LZ_TAILQ_H__
#define __LZ_TAILQ_H__

struct lz_tailq_elem;
struct lz_tailq;

typedef struct lz_tailq_elem lz_tailq_elem;
typedef struct lz_tailq      lz_tailq;

typedef void (*lz_tailq_freefn)(void *);
typedef int (*lz_tailq_iterfn)(lz_tailq_elem * elem, void * arg);

lz_tailq      * lz_tailq_new(void);
lz_tailq      * lz_tailq_dup(lz_tailq * tq);
void            lz_tailq_free(lz_tailq * tq);
void            lz_tailq_clear(lz_tailq * tq);

lz_tailq_elem * lz_tailq_elem_new(void * data, size_t len, lz_tailq_freefn freefn);
void            lz_tailq_elem_free(lz_tailq_elem * elem);

lz_tailq_elem * lz_tailq_append(lz_tailq * head, void * data, size_t len, lz_tailq_freefn freefn);
lz_tailq_elem * lz_tailq_append_elem(lz_tailq * head, lz_tailq_elem * elem);
lz_tailq_elem * lz_tailq_prepend(lz_tailq * head, void * data, size_t len, lz_tailq_freefn freefn);
lz_tailq_elem * lz_tailq_prepend_elem(lz_tailq * head, lz_tailq_elem * elem);

lz_tailq_elem * lz_tailq_first(lz_tailq * head);
lz_tailq_elem * lz_tailq_last(lz_tailq * head);
lz_tailq_elem * lz_tailq_next(lz_tailq_elem * elem);
lz_tailq_elem * lz_tailq_prev(lz_tailq_elem * elem);

int             lz_tailq_elem_remove(lz_tailq_elem * elem);
int             lz_tailq_for_each(lz_tailq * head, lz_tailq_iterfn iterfn, void * arg);

void          * lz_tailq_elem_data(lz_tailq_elem * elem);
lz_tailq      * lz_tailq_elem_head(lz_tailq_elem * elem);
size_t          lz_tailq_elem_size(lz_tailq_elem * elem);
size_t          lz_tailq_size(lz_tailq * head);

lz_tailq_elem * lz_tailq_elem_find(lz_tailq * tq, void * data);
void          * lz_tailq_get_at_index(lz_tailq * head, int index);

size_t          lz_tailq_size(lz_tailq * head);
#endif

