/*
SYNTAX FOR cli:

1000th-summer --distort song.wav
*/

#include <cstddef>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <utility>

#include "../../libs/AudioFile/AudioFile.h"
#include "../tools/tools.h"

// noArgsSingleInput
// intArgSingleInput
// noArgsTwoInput
// intArgMultioutput

std::string remove_extension(const std::string &path) {
  if (path == "." || path == "..")
    return path;

  size_t pos = path.find_last_of("\\/.");
  if (pos != std::string::npos && path[pos] == '.')
    return path.substr(0, pos);

  return path;
}

// std::string nameSingleInput(char **argv) {
//   std::string stem = remove_extension(argv[2]);
//   std::string op = argv[1];
//   op.erase(0, 1);

//   return stem + op;
// }

// std::string nameTwoInput(char **argv) {
//   std::string stem1 = remove_extension(argv[2]);
//   std::string stem2 = remove_extension(argv[3]);
//   std::string op = argv[1];
//   op.erase(0, 1);

//   return stem1 + "-" + stem2 + op;
// }


void noArgsSingleInput(std::string path,
                       AudioFile<double> &wav) {
  wav.load(path);
}

void noArgsTwoInput(std::string path1, std::string path2,
                    AudioFile<double> &wav1, AudioFile<double> &wav2) {
  wav1.load(path1);
  wav2.load(path2);
}

std::vector<AudioFile<double>> parse(std::string path,
                                     std::string &filename) {

  std::vector<AudioFile<double>> wavs;

  AudioFile<double> wav1;
  //AudioFile<double> wav2;

  std::ifstream file;


  


  noArgsSingleInput(path, wav1);
  filename = "fft test"; //nameSingleInput(argv);
  return fastFourierTransform(wav1);


  //ucase("--ifft") : noArgsTwoInput(argc, argv, command, wav1, wav2);
  //filename = nameTwoInput(argv);
  //wavs.push_back(inverseFastFourierTransform(wav1, wav2));
  //break;



  return wavs;
}
