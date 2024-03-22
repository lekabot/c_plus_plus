#include "main_tests.h"

int main(int argc, char **argv) {
  std::vector<int> v(5);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
