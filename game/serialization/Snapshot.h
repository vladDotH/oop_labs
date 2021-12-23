#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include <QJsonObject>

template<class IN, class OUT>
class Snapshot {
public:

    virtual QJsonObject serialize(IN) = 0;

    virtual OUT deserialize(QJsonObject) = 0;
};

#endif //SNAPSHOT_H
