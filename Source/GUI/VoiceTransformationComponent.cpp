#include "VoiceTransformationComponent.h"

// Constructor
VoiceTransformationComponent::VoiceTransformationComponent() {
    // Initialize UI components
    pitchSlider.setRange(0.0, 2.0);
    pitchSlider.setValue(1.0);
    pitchSlider.setTextValueSuffix("x");
    pitchSlider.onValueChange = [this] { updatePitch(); };

    formantSlider.setRange(0.5, 2.0);
    formantSlider.setValue(1.0);
    formantSlider.setTextValueSuffix("x");

    // New voice character selection
    voiceCharacterComboBox.addItem("Default", 1);
    voiceCharacterComboBox.addItem("Character A", 2);
    voiceCharacterComboBox.addItem("Character B", 3);
    voiceCharacterComboBox.onChange = [this] { updateVoiceCharacter(); };
}

// Method to update voice character
void VoiceTransformationComponent::updateVoiceCharacter() {
    int selectedCharacter = voiceCharacterComboBox.getSelectedId();
    ParameterManager::setParameter("VoiceCharacter", selectedCharacter);
}

// Other methods...
