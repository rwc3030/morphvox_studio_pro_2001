#include "gtest/gtest.h"
#include "VoiceTransformer.h"
#include "ParameterManager.h"

class VoiceTransformerTest : public ::testing::Test {
protected:
    VoiceTransformer transformer;

    void SetUp() override {
        // Initialize parameters for testing
        ParameterManager::setParameter("PitchShift", 1.0f);
        ParameterManager::setParameter("FormantShift", 1.0f);
    }
};

TEST_F(VoiceTransformerTest, TestExtremePitchShift) {
    float inputBuffer[5] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    float outputBuffer[5];
    
    // Test with pitch shift of 0
    ParameterManager::setParameter("PitchShift", 0.0f);
    transformer.processAudio(inputBuffer, outputBuffer, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(outputBuffer[i], inputBuffer[i]);
    }

    // Test with negative pitch shift
    ParameterManager::setParameter("PitchShift", -1.0f);
    transformer.processAudio(inputBuffer, outputBuffer, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(outputBuffer[i], inputBuffer[i]);
    }
}

TEST_F(VoiceTransformerTest, TestValidPitchShift) {
    float inputBuffer[5] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float outputBuffer[5];

    // Test with valid pitch shift
    ParameterManager::setParameter("PitchShift", 2.0f);
    transformer.processAudio(inputBuffer, outputBuffer, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(outputBuffer[i], inputBuffer[i] * 2.0f);
    }
}
