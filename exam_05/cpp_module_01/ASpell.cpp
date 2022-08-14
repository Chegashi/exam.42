#include "ASpell.hpp"
#include "ATarget.hpp"

void ASpell::launch(ATarget const &rhs) const { rhs.getHitBySpell(*this); }