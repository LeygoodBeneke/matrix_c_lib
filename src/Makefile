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

all: clean s21_matrix.a
deafult: all
s21_matrix.o: *.c
	gcc $(FLAGS) -c $^
s21_matrix.a: s21_matrix.o
	ar cr s21_matrix.a *.o
clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda s21_test report
test: clean
	gcc $(FLAGS) $(COVERAGE) -o s21_test tests/s21_test.c tests/source/*.c s21_matrix.c $(LDFLAGS)
	./s21_test
add_coverage:
	$(eval FLAGS += --coverage)
gcov_report: add_coverage test
	./s21_test
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details -g -k -r . --html --html-details --filter s21_matrix.c
	$(OPEN_CM) gcov_report.html
