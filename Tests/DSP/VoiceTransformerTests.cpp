#include "VoiceTransformer.h"
#include "gtest/gtest.h"

TEST(VoiceTransformerTests, HandlesExtremePitchShift) {
    VoiceTransformer transformer;
    float inputBuffer[1] = { 1.0f };
    float outputBuffer[1];

    // Test with pitch shift of 0
    ParameterManager::setParameter("PitchShift", 0.0f);
    transformer.processAudio(inputBuffer, outputBuffer, 1);
    EXPECT_EQ(outputBuffer[0], inputBuffer[0]); // Expect no change

    // Test with negative pitch shift
    ParameterManager::setParameter("PitchShift", -1.0f);
    transformer.processAudio(inputBuffer, outputBuffer, 1);
    EXPECT_EQ(outputBuffer[0], inputBuffer[0]); // Expect no change
}
