#include "s21_test.h"

void print_info(Suite *suite) {
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  if (failed_count != 0) {
    printf("FAILED\n");
  } else {
    printf("SUCCESS\n");
  }
}

int main() {
  Suite *suites[] = {test_create_matrix(),
					 test_eq_matrix(),
				 	 test_sum_matrix(),
                     NULL};

  for (int i = 0; suites[i] != NULL; i++) {
    print_info(suites[i]);
  }

  return 0;
}

