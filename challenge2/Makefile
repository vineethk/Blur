BENCHMARK=challenge2
TARGET=blur
TEST_IDS?=0
TEST_NUM=24
SOURCE=blur.c
IGNORE?="blur.c"
# to run the python tests instead of the output diff based tests
PYTESTS="-py"
TEST_SCRIPT="wrapped_tests.py"

ifneq ("$(wildcard local.mk)","") 
include local.mk 
endif

include $(MUSE_HOME)/pliny-software-evolution/pliny-se/test/etc/Makefile
