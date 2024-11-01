#include "VoiceTransformationComponent.h"
#include "ParameterManager.h"

VoiceTransformationComponent::VoiceTransformationComponent() {
    // Initialize UI components
    pitchSlider.setRange(0.0, 2.0);
    pitchSlider.setValue(1.0);
    pitchSlider.setTextValueSuffix("x");
    pitchSlider.onValueChange = [this] { updatePitch(); };

    formantSlider.setRange(0.5, 2.0);
    formantSlider.setValue(1.0);
    formantSlider.setTextValueSuffix("x");
    formantSlider.onValueChange = [this] { updateFormant(); };

    addAndMakeVisible(pitchSlider);
    addAndMakeVisible(formantSlider);
}

void VoiceTransformationComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void VoiceTransformationComponent::resized() {
    pitchSlider.setBounds(10, 10, getWidth() - 20, 20);
    formantSlider.setBounds(10, 40, getWidth() - 20, 20);
}

void VoiceTransformationComponent::updatePitch() {
    ParameterManager::setParameter("PitchShift", pitchSlider.getValue());
}

void VoiceTransformationComponent::updateFormant() {
    ParameterManager::setParameter("FormantShift", formantSlider.getValue());
}
