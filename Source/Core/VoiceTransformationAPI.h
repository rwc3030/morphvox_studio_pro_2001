#ifndef VOICETRANSFORMATIONAPI_H
#define VOICETRANSFORMATIONAPI_H

void processVoiceTransformation(float* inputBuffer, float* outputBuffer, int numSamples);
void setFormantShift(float value);

#endif // VOICETRANSFORMATIONAPI_H
