#ifndef __LZ_KVMAP_H__
#define __LZ_KVMAP_H__

struct lz_kvmap_s;
struct lz_kvmap_ent_s;

typedef struct lz_kvmap_s     lz_kvmap;
typedef struct lz_kvmap_ent_s lz_kvmap_ent;

typedef int (*lz_kvmap_iterfn)(lz_kvmap_ent * ent, void * arg);

lz_kvmap     * lz_kvmap_new(uint32_t n_buckets);
lz_kvmap_ent * lz_kvmap_add(lz_kvmap * map, const char * k, void * v, void (* freefn)(void *));
lz_kvmap_ent * lz_kvmap_add_wklen(lz_kvmap * map, const char * k, size_t l, void * val, void (* freefn)(void *));
lz_kvmap_ent * lz_kvmap_ent_find(lz_kvmap * map, const char * k);
void         * lz_kvmap_ent_val(lz_kvmap_ent * ent);
const char   * lz_kvmap_ent_key(lz_kvmap_ent * ent);
void         * lz_kvmap_find(lz_kvmap * map, const char * k);
int            lz_kvmap_clear(lz_kvmap * map);
int            lz_kvmap_for_each(lz_kvmap * map, lz_kvmap_iterfn iterfn, void * arg);
void           lz_kvmap_free(lz_kvmap *);

lz_kvmap_ent * lz_kvmap_first(lz_kvmap * map);
lz_kvmap_ent * lz_kvmap_next(lz_kvmap_ent * ent);

size_t         lz_kvmap_ent_get_klen(lz_kvmap_ent * ent);
size_t         lz_kvmap_get_size(lz_kvmap * map);

int            lz_kvmap_remove(lz_kvmap * map, const char * key);
int            lz_kvmap_remove_ent(lz_kvmap * map, lz_kvmap_ent * ent);
#endif

