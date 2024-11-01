#include "VoiceTransformer.h"
#include "ParameterManager.h"
#include "AudioProcessingUtils.h"
#include <cmath>

VoiceTransformer::VoiceTransformer() {
    // Initialize parameters
    initParameters();
}

void VoiceTransformer::processAudio(float* inputBuffer, float* outputBuffer, int numSamples) {
    // Use the utility function to process audio
    processAudioBuffer(inputBuffer, outputBuffer, numSamples);
}

void VoiceTransformer::initParameters() {
    // Initialize parameters for voice transformation
    ParameterManager::setParameter("PitchShift", 1.0f);
    ParameterManager::setParameter("FormantShift", 1.0f);
    ParameterManager::setParameter("VoiceCharacter", 1); // Default character
}

float VoiceTransformer::applyTransformation(float sample) {
    // Apply pitch and formant shifting
    float pitchShift = ParameterManager::getParameter("PitchShift");
    float formantShift = ParameterManager::getParameter("FormantShift");

    // Validate parameter values
    if (pitchShift < 0.0f || pitchShift > 2.0f || formantShift < 0.0f || formantShift > 2.0f) {
        return sample; // Return original sample if parameters are invalid
    }

    // Transformation logic here...
    return sample; // Placeholder for actual transformation logic
}

void VoiceTransformer::applyVoiceCharacter(int character) {
    // Logic to modify the voice based on the selected character
    if (character < 1 || character > 3) {
        return; // Invalid character, do nothing
    }

    switch (character) {
        case 1:
            // Default character processing
            break;
        // Additional cases for other characters...
    }
}
