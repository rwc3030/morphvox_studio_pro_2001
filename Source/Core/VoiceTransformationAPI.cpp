#include "VoiceTransformationAPI.h"
#include "VoiceTransformer.h"

extern "C" void processVoiceTransformationAPI(float* inputBuffer, float* outputBuffer, int numSamples) {
    VoiceTransformer transformer;
    transformer.processAudio(inputBuffer, outputBuffer, numSamples);
}
