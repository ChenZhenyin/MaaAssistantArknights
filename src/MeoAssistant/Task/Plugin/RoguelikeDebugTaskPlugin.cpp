#include "RoguelikeDebugTaskPlugin.h"

#include "Controller.h"
#include "RuntimeStatus.h"

bool asst::RoguelikeDebugTaskPlugin::verify(AsstMsg msg, const json::value& details) const
{
    if (details.get("subtask", std::string()) != "ProcessTask") {
        return false;
    }

    if (msg == AsstMsg::SubTaskError) {
        return true;
    }

    auto roguelike_name_opt = m_status->get_properties("roguelike_name");
    if (!roguelike_name_opt) {
        return false;
    }
    const auto& roguelike_name = roguelike_name_opt.value() + "@";
    std::string task = details.get("details", "task", std::string());
    if (msg == AsstMsg::SubTaskStart && details.get("subtask", std::string()) == "ProcessTask" &&
        task == roguelike_name + "ExitThenAbandon") {
        return true;
    }

    return false;
}

bool asst::RoguelikeDebugTaskPlugin::_run()
{
    return save_img("debug/roguelike/");
}
