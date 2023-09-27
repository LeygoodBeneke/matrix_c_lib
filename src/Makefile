FLAGS=-Wall -Werror -Wextra -std=c11
COVERAGE=
UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lm -lrt -lpthread -lsubunit
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif

all: clean proj_matrix.a
deafult: all
proj_matrix.o: *.c
	gcc $(FLAGS) -c $^
proj_matrix.a: proj_matrix.o
	ar cr proj_matrix.a *.o
clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda proj_test report
test: clean proj_matrix.a
	gcc $(FLAGS) $(COVERAGE) -o proj_test tests/proj_test.c tests/source/*.c proj_matrix.a $(LDFLAGS)
	./proj_test
add_coverage:
	$(eval FLAGS += --coverage)
gcov_report: add_coverage test
	./proj_test
	gcov -b -l -p -c proj_*.gcno
	gcovr -o gcov_report.html --html --html-details -g -k -r . --html --html-details --filter proj_matrix.c
	$(OPEN_CM) gcov_report.html
