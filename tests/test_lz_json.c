#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>

#include <check.h>

#include "internal.h"
#include "tailq/lz_tailq.h"
#include "kvmap/lz_kvmap.h"
#include "json/lz_json.h"

static ssize_t
load_file(const char * fname, char * outbuf, size_t obuf_sz) {
    FILE * fp;
    size_t nread;

    if (!(fp = fopen(fname, "r"))) {
        return -1;
    }

    nread = (ssize_t)fread(outbuf, 1, obuf_sz, fp);

    fclose(fp);

    return nread;
}

START_TEST(test_parse_buf) {
    char buf[getpagesize() * 2];
    ssize_t jparsed;
    ssize_t nread;
    lz_json * json;

    nread = load_file("./test1.json", buf, sizeof(buf));
    ck_assert_int_gt(nread, 0);

    json = lz_json_parse_buf(buf, nread, &jparsed);
    ck_assert(json != NULL);

    lz_json_free(json);

}
END_TEST

START_TEST(test_parse_file) {
    lz_json * json;
}
END_TEST

Suite *
lz_json_suite(void) {
    Suite * suite = suite_create("lz_json");
    TCase * tcase = tcase_create("case");

    tcase_add_test(tcase, test_parse_buf);
    tcase_add_test(tcase, test_parse_file);
    suite_add_tcase(suite, tcase);

    return suite;
}

int
main(int argc, char ** argv) {
    int       tests_failed;
    Suite   * suite;
    SRunner * srun;

    suite        = lz_json_suite();
    srun         = srunner_create(suite);

    srunner_run_all(srun, CK_NORMAL);

    tests_failed = srunner_ntests_failed(srun);

    srunner_free(srun);

    return (tests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

