#include "mergesort.h"
#include <string>
#include <iostream>
#include <cstdlib>

namespace {
using std::cout;
using std::string;

const string default_app_name = "mergesort";

struct app_arguments {
  bool success;
  string app_name;
  size_t array_size;
};

app_arguments parseArgs(const int& argc, const char** argv) {
  app_arguments args;
  args.success = false;

  if(argc < 1)
    return args;
  args.app_name = argv[0];

  if(argc < 2)
    return args;
  args.array_size = strtol(argv[1], NULL, 10);

  args.success = true;
  return args;
}

string usage_message(const string& app_name) {
  return "usage: " + (app_name.empty() ? default_app_name : app_name) + " size" + "\n";
}
} // namespace

int main(int argc, char* argv[]) {
  app_arguments args = parseArgs(argc, (const char**)argv);
  if(!args.success) {
    cout << usage_message(args.app_name);
    return 0;
  }

  patterns::forkjoin_mergesort(args.array_size);
  return 0;
}
