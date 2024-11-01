#include "VoiceTransformer.h"
#include "ParameterManager.h"
#include "AudioProcessingUtils.h"
#include <cmath>

VoiceTransformer::VoiceTransformer() {
    // Initialize parameters
    initParameters();
}

void VoiceTransformer::processAudio(float* inputBuffer, float* outputBuffer, int numSamples) {
    // Check for null pointers and invalid sample count
    if (inputBuffer == nullptr || outputBuffer == nullptr || numSamples <= 0) {
        return; // Early exit to avoid processing
    }

    // Process audio buffer
    for (int i = 0; i < numSamples; ++i) {
        if (inputBuffer[i] < 0.0f) {
            outputBuffer[i] = 0.0f; // Handle negative values
        } else if (inputBuffer[i] > 1.0f) {
            outputBuffer[i] = 1.0f; // Cap values above 1.0
        } else {
            outputBuffer[i] = inputBuffer[i]; // Placeholder for actual transformation logic
        }
    }
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
