#include "StartGameDialog.h"

StartGameDialog::StartGameDialog(QWidget *parent, const Qt::WindowFlags &f = Qt::WindowFlags())
        : QDialog(parent, f) {
    setWindowTitle("генерация");
    lt = new QVBoxLayout(this);

    fld = new QGroupBox("параметры игры", this);
    enems = new QGroupBox("параметры врагов", this);
    items = new QGroupBox("параметры предметов", this);

    fldlt = new QGridLayout(fld);
    enemslt = new QGridLayout(enems);
    itemslt = new QGridLayout(items);

    x = new QSpinBox(fld);
    x->setRange(3, 100);
    y = new QSpinBox(fld);
    y->setRange(3, 100);
    range = new QSpinBox(fld);
    range->setRange(1, 50);

    heals = new QSpinBox(items);
    heals->setRange(0, 30);
    weapons = new QSpinBox(items);
    weapons->setRange(0, 30);
    armors = new QSpinBox(items);
    armors->setRange(0, 30);

    lights = new QSpinBox(enems);
    lights->setRange(0, 30);
    mediums = new QSpinBox(enems);
    mediums->setRange(0, 30);
    heavies = new QSpinBox(enems);
    heavies->setRange(0, 30);

    collect = new QSpinBox(fld);
    collect->setRange(-1, 30);
    kill = new QSpinBox(fld);
    kill->setRange(-1, 30);

    fldlt->addWidget(new QLabel("ширина"), 0, 0);
    fldlt->addWidget(x, 0, 1);
    fldlt->addWidget(new QLabel("высота"), 1, 0);
    fldlt->addWidget(y, 1, 1);
    fldlt->addWidget(new QLabel("собрать предметов"), 2, 0);
    fldlt->addWidget(collect, 2, 1);
    fldlt->addWidget(new QLabel("убить врагов"), 3, 0);
    fldlt->addWidget(kill, 3, 1);
    fldlt->addWidget(new QLabel("радиус видимости врагов"), 4, 0);
    fldlt->addWidget(range, 4, 1);

    enemslt->addWidget(new QLabel("лёгкие"), 0, 0);
    enemslt->addWidget(lights, 0, 1);
    enemslt->addWidget(new QLabel("средние"), 1, 0);
    enemslt->addWidget(mediums, 1, 1);
    enemslt->addWidget(new QLabel("тяжёлые"), 2, 0);
    enemslt->addWidget(heavies, 2, 1);

    itemslt->addWidget(new QLabel("здоровье"), 0, 0);
    itemslt->addWidget(heals, 0, 1);
    itemslt->addWidget(new QLabel("броня"), 1, 0);
    itemslt->addWidget(armors, 1, 1);
    itemslt->addWidget(new QLabel("оружие"), 2, 0);
    itemslt->addWidget(weapons, 2, 1);

    fld->setLayout(fldlt);
    enems->setLayout(enemslt);
    items->setLayout(itemslt);

    lt->addWidget(fld);
    lt->addWidget(enems);
    lt->addWidget(items);
    start = new QPushButton("Сгенерировать", this);
    lt->addWidget(start);

    connect(start, &QPushButton::pressed, [=]() {
        emit generate(Vec2D(x->value(), y->value()), collect->value(), kill->value(), range->value(),
                      heals->value(), armors->value(), weapons->value(), lights->value(), mediums->value(),
                      heavies->value());
    });
}
