#include "gtest/gtest.h"
#include "VoiceTransformer.h"

TEST(VoiceTransformerTest, ApplyTransformation_ValidInput) {
    VoiceTransformer transformer;
    float inputBuffer[5] = {0.0f, 0.5f, 1.0f, 1.5f, 2.0f};
    float outputBuffer[5];
    ParameterManager::setParameter("PitchShift", 1.0f);
    ParameterManager::setParameter("FormantShift", 1.0f);
    
    transformer.processAudio(inputBuffer, outputBuffer, 5);
    
    // Add assertions to verify outputBuffer values
}

TEST(VoiceTransformerTest, ApplyTransformation_ExtremePitchShift) {
    VoiceTransformer transformer;
    float inputBuffer[5] = {0.0f, 0.5f, 1.0f, 1.5f, 2.0f};
    float outputBuffer[5];
    
    ParameterManager::setParameter("PitchShift", 3.0f); // Exceeding max
    ParameterManager::setParameter("FormantShift", 1.0f);
    
    transformer.processAudio(inputBuffer, outputBuffer, 5);
    
    // Add assertions to verify outputBuffer values are capped
}
