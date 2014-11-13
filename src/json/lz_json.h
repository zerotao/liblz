#ifndef __TS_JSON_H__
#define __TS_JSON_H__

enum lz_json_vtype_e {
    lz_json_vtype_string = 0,
    lz_json_vtype_number,
    lz_json_vtype_object,
    lz_json_vtype_array,
    lz_json_vtype_bool,
    lz_json_vtype_null
};

struct lz_json_s;

typedef enum lz_json_vtype_e lz_json_vtype;
typedef struct lz_json_s     lz_json;

typedef int (*lz_json_key_filtercb)(const char * key, lz_json * val);

lz_json * lz_json_parse_buf(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_file(const char * filename, size_t * n_read);
lz_json * lz_json_parse_object(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_array(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_value(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_string(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_number(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_key(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_null(const char * data, size_t len, size_t * n_read);
lz_json * lz_json_parse_boolean(const char * data, size_t len, size_t * n_read);
void      lz_json_free(lz_json * js);


lz_json_vtype lz_json_get_type(lz_json * js);
lz_kvmap    * lz_json_get_object(lz_json * js);
lz_tailq    * lz_json_get_array(lz_json * js);
lz_json     * lz_json_get_array_index(lz_json * js, int index);
unsigned int  lz_json_get_number(lz_json * js);
const char  * lz_json_get_string(lz_json * js);
bool          lz_json_get_boolean(lz_json * js);
char          lz_json_get_null(lz_json * js);
ssize_t       lz_json_get_size(lz_json * js);
lz_json     * lz_json_path_get(lz_json * js, const char * path);

lz_json     * lz_json_new_object(void);
lz_json     * lz_json_new_array(void);
lz_json     * lz_json_string_new(const char * str);
lz_json     * lz_json_string_new_len(const char * str, size_t len);
lz_json     * lz_json_number_new(unsigned int num);
lz_json     * lz_json_boolean_new(bool boolean);
lz_json     * lz_json_null_new(void);

int           lz_json_object_add(lz_json * obj, const char * key, lz_json * val);
int           lz_json_object_add_klen(lz_json * o, const char * k, size_t kl, lz_json * v);
int           lz_json_array_add(lz_json * array, lz_json * val);
int           lz_json_add(lz_json * obj, const char * k, lz_json * val);

ssize_t       lz_json_to_buffer(lz_json * json, char * buf, size_t buf_len);
ssize_t       lz_json_to_buffer_nescp(lz_json * json, char * buf, size_t buf_len);
char        * lz_json_to_buffer_alloc(lz_json * json, size_t * len);
int           lz_json_compare(lz_json * j1, lz_json * j2, lz_json_key_filtercb cb);

#endif

