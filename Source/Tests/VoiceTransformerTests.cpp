#include "gtest/gtest.h"
#include "VoiceTransformer.h"
#include "ParameterManager.h"

class VoiceTransformerTests : public ::testing::Test {
protected:
    VoiceTransformer transformer;

    void SetUp() override {
        // Set default parameters for tests
        ParameterManager::setParameter("PitchShift", 1.0f);
        ParameterManager::setParameter("FormantShift", 1.0f);
    }
};

TEST_F(VoiceTransformerTests, TestApplyTransformation_ValidInput) {
    float input = 1.0f;
    ParameterManager::setParameter("PitchShift", 1.5f);
    float output = transformer.applyTransformation(input);
    EXPECT_EQ(output, input * 1.5f);
}

TEST_F(VoiceTransformerTests, TestApplyTransformation_InvalidPitchShift) {
    float input = 1.0f;
    ParameterManager::setParameter("PitchShift", -1.0f);
    float output = transformer.applyTransformation(input);
    EXPECT_EQ(output, input); // Should return original sample
}

TEST_F(VoiceTransformerTests, TestApplyTransformation_ExtremePitchShift) {
    float input = 1.0f;
    ParameterManager::setParameter("PitchShift", 3.0f); // Exceeds max
    float output = transformer.applyTransformation(input);
    EXPECT_EQ(output, input * 2.0f); // Should cap at max
}

TEST(VoiceTransformerTest, ApplyTransformation_ValidInput) {
    VoiceTransformer transformer;
    float inputBuffer[5] = {0.0f, 0.5f, 1.0f, 1.5f, 2.0f};
    float outputBuffer[5];
    ParameterManager::setParameter("PitchShift", 1.0f);
    ParameterManager::setParameter("FormantShift", 1.0f);
    
    transformer.processAudio(inputBuffer, outputBuffer, 5);
    
    // Verify outputBuffer values
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(outputBuffer[i], inputBuffer[i]);
    }
}

TEST(VoiceTransformerTest, ApplyTransformation_ExtremePitchShift) {
    VoiceTransformer transformer;
    float inputBuffer[5] = {0.0f, 0.5f, 1.0f, 1.5f, 2.0f};
    float outputBuffer[5];
    
    ParameterManager::setParameter("PitchShift", 3.0f); // Exceeding max
    ParameterManager::setParameter("FormantShift", 1.0f);
    
    transformer.processAudio(inputBuffer, outputBuffer, 5);
    
    // Verify outputBuffer values are capped
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(outputBuffer[i], inputBuffer[i] * 2.0f); // Should cap at max
    }
}
