#ifndef TOOLS_H
#define TOOLS_H
#include "../../libs/AudioFile/AudioFile.h"

AudioFile<double> normalize(AudioFile<double> wav);

std::vector<AudioFile<double>> fastFourierTransform(AudioFile<double> wav);
AudioFile<double> inverseFastFourierTransform(AudioFile<double> wav1, AudioFile<double> wav2);

#endif