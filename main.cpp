#include <iostream>

#include "rest/server.h"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: app <address> <kPort> <concurrency>\n"
              << "Example:\n"
              << "    http-server-async 0.0.0.0 8080 1\n";
    return EXIT_FAILURE;
  }
  char* const address = argv[1];
  int const port = static_cast<unsigned short>(std::atoi(argv[2]));
  int const threads = std::max<int>(1, std::atoi(argv[3]));
  Server server{threads};
  char wait;

  std::cout << "Starting server at: " << address << ":" << port << std::endl;
  server.run(address, port);
  std::cout << "Server running - press any key plus enter to stop ..." << std::endl;
  std::cin >> wait;
 
  return EXIT_SUCCESS;
}