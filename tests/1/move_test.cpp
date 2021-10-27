#include <iostream>
#include <viewers/console/ConsoleFieldView.h>
#include <field/FieldBuilder.h>
#include "field/Field.h"
#include "loggers/FileLogger.h"
#include "loggers/formats/TimeFormat.h"

using namespace std;

int main() {
    shared_ptr<Logger> lg = make_shared<FileLogger>("log.txt");
    lg->setFmt(make_shared<TimeFormat>());
    ConsoleFieldView fv;
    shared_ptr<Field> f1 = FieldBuilder().setSize(Vec2D(5, 5)).setType(FieldBuilder::Type::BOX).build();
    f1->addLogger(lg);
    fv.setField(f1);
    fv.showInfo(cout);
    cout << fv << endl;

    shared_ptr<Field> f2 = make_shared<Field>(std::move(*f1));
    f2->addLogger(lg);
    fv.showInfo(cout);
    cout << fv << endl;
    fv.setField(f2);
    fv.showInfo(cout);
    cout << fv << endl;

    shared_ptr<Field> f3 = FieldBuilder().setSize(Vec2D(2, 3)).setType(FieldBuilder::Type::DEFAULT).build();
    f3->addLogger(lg);
    *f3 = std::move(*f2);

    fv.setField(f1);
    fv.showInfo(cout);
    cout << fv << endl;

    fv.setField(f2);
    fv.showInfo(cout);
    cout << fv << endl;

    fv.setField(f3);
    fv.showInfo(cout);
    cout << fv << endl;
}
