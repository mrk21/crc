#include <crc/application.hpp>
#include <crc/util.hpp>

int main(void) {
  crc::util::singleton<crc::application>()->execute();
  return 0;
}
