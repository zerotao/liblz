add_library(lz_json ${LIBLZ_OBJ_TYPE} lz_json.c)

install(TARGETS lz_json DESTINATION lib)
install(FILES lz_json.h DESTINATION include/liblz/json)
