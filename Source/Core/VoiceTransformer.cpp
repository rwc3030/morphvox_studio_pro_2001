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

    // Handle extreme values for pitch and formant shifts
    if (pitchShift == 0.0f) {
        return sample; // No pitch shift
    }
    if (pitchShift < 0.0f) {
        // Handle negative pitch shift if needed
        // For now, return original sample
        return sample;
    }

    // Apply transformation logic here (placeholder)
    // This is where the actual transformation would occur
    return sample * pitchShift; // Simplified transformation for demonstration
}

extern "C" void processVoiceTransformation(float* inputBuffer, float* outputBuffer, int numSamples) {
    VoiceTransformer transformer;
    transformer.processAudio(inputBuffer, outputBuffer, numSamples);
}
