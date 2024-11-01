#include "VoiceTransformationAPI.h"
#include "VoiceTransformer.h"
#include "ParameterManager.h"

extern "C" void processVoiceTransformation(float* inputBuffer, float* outputBuffer, int numSamples) {
    VoiceTransformer transformer;

    // Validate input parameters
    if (inputBuffer == nullptr || outputBuffer == nullptr || numSamples <= 0) {
        return; // Early exit to avoid processing
    }

    transformer.processAudio(inputBuffer, outputBuffer, numSamples);
    
    // Handle voice character processing
    int voiceCharacter = ParameterManager::getParameter("VoiceCharacter");
    if (voiceCharacter >= 1 && voiceCharacter <= 3) {
        transformer.applyVoiceCharacter(voiceCharacter);
    }
}
