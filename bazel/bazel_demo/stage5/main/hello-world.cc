#include "absl/strings/str_join.h"
#include "zlib.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

std::string get_greet(const std::string &who) {
  std::vector<std::string> v = {"Hello"};
  v.push_back(who);
  return absl::StrJoin(v, " ");
}

int main(int argc, char **argv) {
  std::string who = "world";
  if (argc > 1) {
    who = argv[1];
  }
  std::string greet_str = get_greet(who);
  std::cout << greet_str << std::endl;
  printf("Uncompressed greet_str size is: %lu\n", greet_str.length());

  char compressed_greet_cstr[100];

  // zlib struct
  z_stream defstream;
  defstream.zalloc = Z_NULL;
  defstream.zfree = Z_NULL;
  defstream.opaque = Z_NULL;
  // setup "a" as the input and "b" as the compressed output
  defstream.avail_in =
      greet_str.length() + 1; // size of input, string + terminator
  defstream.next_in = (Bytef *)greet_str.data();             // input char array
  defstream.avail_out = (uInt)sizeof(compressed_greet_cstr); // size of output
  defstream.next_out = (Bytef *)compressed_greet_cstr; // output char array

  // the actual compression work.
  deflateInit(&defstream, Z_BEST_COMPRESSION);
  deflate(&defstream, Z_FINISH);
  deflateEnd(&defstream);

  // print the size of the output.
  printf("Uncompressed greet_str size is: %lu\n", defstream.total_out);

  return 0;
}
