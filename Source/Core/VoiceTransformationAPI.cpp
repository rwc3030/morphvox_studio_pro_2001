#include "VoiceTransformationAPI.h"
#include "VoiceTransformer.h"

extern "C" void processVoiceTransformation(float* inputBuffer, float* outputBuffer, int numSamples) {
    VoiceTransformer transformer;
    transformer.processAudio(inputBuffer, outputBuffer, numSamples);
}

void setFormantShift(float value) {
    ParameterManager::setParameter("FormantShift", value);
}
