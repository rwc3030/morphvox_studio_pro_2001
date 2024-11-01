#include "gtest/gtest.h"
#include "VoiceTransformer.h"

TEST(VoiceTransformerTest, ApplyTransformation_ValidParameters) {
    VoiceTransformer transformer;
    float inputSample = 0.5f;
    ParameterManager::setParameter("PitchShift", 1.0f);
    ParameterManager::setParameter("FormantShift", 1.0f);
    
    float outputSample = transformer.applyTransformation(inputSample);
    EXPECT_NEAR(outputSample, expectedValue, tolerance); // Replace with actual expected value and tolerance
}

TEST(VoiceTransformerTest, ApplyTransformation_InvalidParameters) {
    VoiceTransformer transformer;
    float inputSample = 0.5f;
    ParameterManager::setParameter("PitchShift", -1.0f); // Invalid pitch shift
    ParameterManager::setParameter("FormantShift", 1.0f);
    
    float outputSample = transformer.applyTransformation(inputSample);
    EXPECT_EQ(outputSample, inputSample); // Should return original sample
}
