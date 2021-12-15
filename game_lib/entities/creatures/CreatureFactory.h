#ifndef CREATUREFACTORY_H
#define CREATUREFACTORY_H

#include "../EntityFactory.h"

class CreatureFactory : public EntityFactory {
public:
    CreatureFactory(std::shared_ptr<Creature> e) : EntityFactory(e) {}
};


#endif //CREATUREFACTORY_H
