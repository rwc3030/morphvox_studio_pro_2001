#include "gtest/gtest.h"
#include "VoiceTransformer.h"
#include "ParameterManager.h"

TEST(VoiceTransformerTests, ApplyTransformation_ValidParameters) {
    VoiceTransformer transformer;
    ParameterManager::setParameter("PitchShift", 1.0f);
    ParameterManager::setParameter("FormantShift", 1.0f);
    
    float inputSample = 0.5f;
    float outputSample = transformer.applyTransformation(inputSample);
    
    EXPECT_NEAR(outputSample, inputSample, 0.01); // Assuming no transformation for default values
}

TEST(VoiceTransformerTests, ApplyTransformation_InvalidParameters) {
    VoiceTransformer transformer;
    ParameterManager::setParameter("PitchShift", -1.0f); // Invalid
    ParameterManager::setParameter("FormantShift", 3.0f); // Invalid
    
    float inputSample = 0.5f;
    float outputSample = transformer.applyTransformation(inputSample);
    
    EXPECT_EQ(outputSample, inputSample); // Should return original sample
}

TEST(VoiceTransformerTests, ApplyVoiceCharacter_ValidCharacter) {
    VoiceTransformer transformer;
    transformer.applyVoiceCharacter(1); // Valid character
    // Add assertions based on expected behavior
}

TEST(VoiceTransformerTests, ApplyVoiceCharacter_InvalidCharacter) {
    VoiceTransformer transformer;
    transformer.applyVoiceCharacter(4); // Invalid character
    // Add assertions based on expected behavior
}
