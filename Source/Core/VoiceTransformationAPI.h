#ifndef VOICETRANSFORMATIONAPI_H
#define VOICETRANSFORMATIONAPI_H

void processVoiceTransformation(float* inputBuffer, float* outputBuffer, int numSamples);
void setFormantShift(float value);
void setVoiceCharacter(int character); // New function declaration
void setPitchShift(float value); // New function declaration for pitch shift

// Additional function to validate voice character
bool validateVoiceCharacter(int character);

#endif // VOICETRANSFORMATIONAPI_H
