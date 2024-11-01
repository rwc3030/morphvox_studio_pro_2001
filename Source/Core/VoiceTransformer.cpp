#include "VoiceTransformer.h"
#include "ParameterManager.h"

VoiceTransformer::VoiceTransformer() {
    // Initialize parameters
    initParameters();
}

void VoiceTransformer::processAudio(float* inputBuffer, float* outputBuffer, int numSamples) {
    // Check for null input buffer or zero samples
    if (inputBuffer == nullptr || outputBuffer == nullptr || numSamples <= 0) {
        return; // Early exit to avoid processing
    }

    // Process audio with new transformation logic
    for (int i = 0; i < numSamples; ++i) {
        outputBuffer[i] = applyTransformation(inputBuffer[i]);
    }
}

void VoiceTransformer::initParameters() {
    // Initialize parameters for voice transformation
    ParameterManager::setParameter("PitchShift", 1.0f);
    ParameterManager::setParameter("FormantShift", 1.0f);
}

float VoiceTransformer::applyTransformation(float sample) {
    // Apply pitch and formant shifting
    float pitchShift = ParameterManager::getParameter("PitchShift");
    float formantShift = ParameterManager::getParameter("FormantShift");

    // Validate parameter values
    if (pitchShift < 0.0f || formantShift < 0.0f) {
        return sample; // Return original sample if parameters are invalid
    }

    // Handle extreme parameter values
    if (pitchShift > 2.0f) {
        pitchShift = 2.0f; // Cap pitch shift to maximum value
    } else if (pitchShift < 0.5f) {
        pitchShift = 0.5f; // Cap pitch shift to minimum value
    }

    // Transformation logic (placeholder)
    // This is where the actual transformation would be applied
    return sample * pitchShift; // Example transformation
}

extern "C" void processVoiceTransformation(float* inputBuffer, float* outputBuffer, int numSamples) {
    VoiceTransformer transformer;
    transformer.processAudio(inputBuffer, outputBuffer, numSamples);
}
