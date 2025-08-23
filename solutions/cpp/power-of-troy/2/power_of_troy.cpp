#include "power_of_troy.h"

namespace troy
{

  void give_artifact(human &h, std::string artifact_name)
  {
    h.possession = std::make_unique<artifact>(artifact_name);
  }

  void exchange_artifact(std::unique_ptr<artifact> &a1, std::unique_ptr<artifact> &a2)
  {
    std::swap(a1, a2);
  }

  void manifest_power(human &h, std::string pow)
  {
    h.own_power = std::make_shared<power>(pow);
  }

  void use_power(human &caster, human &target)
  {
    target.influenced_by = caster.own_power;
  }
}
