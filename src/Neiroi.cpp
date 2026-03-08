#include "plugin.hpp"

struct FreeNeiroi : Module {
    enum ParamId { PARAMS_LEN };
    enum InputId { INPUTS_LEN };
    enum OutputId { OUTPUTS_LEN };
    enum LightId { LIGHTS_LEN };

    FreeNeiroi() {
        config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
    }

    void process(const ProcessArgs& args) override {
        // Пока пусто
    }
};

struct FreeNeiroiWidget : ModuleWidget {
    FreeNeiroiWidget(FreeNeiroi* module) {
        setModule(module);

        setPanel(createPanel(asset::plugin(pluginInstance, "res/FreeNeiroi.svg")));
    }
};

Model* modelFreeNeiroiModule = createModel<FreeNeiroi, FreeNeiroiWidget>("NeiroiModule");
