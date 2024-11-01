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

    // Add feedback for invalid parameter values
    pitchSlider.onValueChange = [this] {
        if (pitchSlider.getValue() < 0.0 || pitchSlider.getValue() > 2.0) {
            showError("Pitch shift value must be between 0.0 and 2.0.");
        }
    };

    formantSlider.onValueChange = [this] {
        if (formantSlider.getValue() < 0.5 || formantSlider.getValue() > 2.0) {
            showError("Formant shift value must be between 0.5 and 2.0.");
        }
    };
}

void VoiceTransformationComponent::showError(const std::string& message) {
    // Display error message to the user
    // Implementation of error display logic
}
