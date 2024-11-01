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

    voiceCharacterComboBox.addItem("Character 1", 1);
    voiceCharacterComboBox.addItem("Character 2", 2);
    voiceCharacterComboBox.addItem("Character 3", 3);
    voiceCharacterComboBox.onChange = [this] { updateVoiceCharacter(); };
}

void VoiceTransformationComponent::updatePitch() {
    ParameterManager::setParameter("PitchShift", pitchSlider.getValue());
}

void VoiceTransformationComponent::updateFormant() {
    ParameterManager::setParameter("FormantShift", formantSlider.getValue());
}

void VoiceTransformationComponent::updateVoiceCharacter() {
    int selectedCharacter = voiceCharacterComboBox.getSelectedId();
    ParameterManager::setParameter("VoiceCharacter", selectedCharacter);
}
