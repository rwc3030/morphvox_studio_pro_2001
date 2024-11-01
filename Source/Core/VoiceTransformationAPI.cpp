#include "VoiceTransformationAPI.h"
#include "VoiceTransformer.h"

extern "C" void processVoiceTransformation(float* inputBuffer, float* outputBuffer, int numSamples) {
    VoiceTransformer transformer;
    transformer.processAudio(inputBuffer, outputBuffer, numSamples);
    
    // Handle voice character processing
    int voiceCharacter = ParameterManager::getParameter("VoiceCharacter");
    transformer.applyVoiceCharacter(voiceCharacter);
}
