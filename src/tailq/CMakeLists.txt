add_library(lz_tailq ${LIBLZ_OBJ_TYPE} lz_tailq.c)

install(TARGETS lz_tailq DESTINATION lib)
install(FILES lz_tailq.h DESTINATION include/liblz/tailq)
