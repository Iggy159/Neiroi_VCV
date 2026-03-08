#include "plugin.hpp"

struct FreeNeiroi : Module {
    enum ParamId { PARAMS_LEN };
    enum InputId { INPUTS_LEN };
    enum OutputId {
        AUDIO_L_OUTPUT,
        AUDIO_R_OUTPUT,
        OUTPUTS_LEN
    };
    enum LightId { LIGHTS_LEN };

    FreeNeiroi() {
        config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
        configOutput(AUDIO_L_OUTPUT, "Audio Left");
        configOutput(AUDIO_R_OUTPUT, "Audio Right");
    }

    void process(const ProcessArgs& args) override {
        outputs[AUDIO_L_OUTPUT].setVoltage(0.f);
        outputs[AUDIO_R_OUTPUT].setVoltage(0.f);
    }
};

struct FreeNeiroiWidget : ModuleWidget {
    FreeNeiroiWidget(FreeNeiroi* module) {
        setModule(module);
        
        setPanel(createPanel(asset::plugin(pluginInstance, "res/FreeNeiroi.svg")));
        addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 110)), module, FreeNeiroi::AUDIO_L_OUTPUT));
        addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(30, 110)), module, FreeNeiroi::AUDIO_R_OUTPUT));
    }
};

Model* modelFreeNeiroiModule = createModel<FreeNeiroi, FreeNeiroiWidget>("NeiroiModule");
