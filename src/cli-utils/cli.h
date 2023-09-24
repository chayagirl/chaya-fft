#ifndef CLI_H
#define CLI_H

#include "../../libs/AudioFile/AudioFile.h"
std::vector<AudioFile<double>> parse(std::string path,
                                     std::string &filename);

#endif