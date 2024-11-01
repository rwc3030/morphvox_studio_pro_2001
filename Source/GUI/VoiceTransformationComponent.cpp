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

    // New Voice Character Selection
    voiceCharacterDropdown.addItem("Default", 1);
    voiceCharacterDropdown.addItem("Character A", 2);
    voiceCharacterDropdown.addItem("Character B", 3);
    voiceCharacterDropdown.onChange = [this] { updateVoiceCharacter(); };
}

void VoiceTransformationComponent::updatePitch() {
    ParameterManager::setParameter("PitchShift", pitchSlider.getValue());
}

void VoiceTransformationComponent::updateFormant() {
    ParameterManager::setParameter("FormantShift", formantSlider.getValue());
}

void VoiceTransformationComponent::updateVoiceCharacter() {
    int selectedCharacter = voiceCharacterDropdown.getSelectedId();
    ParameterManager::setParameter("VoiceCharacter", selectedCharacter);
}
