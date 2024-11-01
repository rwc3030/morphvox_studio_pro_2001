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
