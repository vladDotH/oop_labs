#ifndef STARTGAMEDIALOG_H
#define STARTGAMEDIALOG_H

#include "core/Vec2D.h"
#include <QDialog>
#include <QGridLayout>
#include <QSpinBox>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>

class StartGameDialog : public QDialog {
Q_OBJECT
protected:
    QVBoxLayout *lt;
    QSpinBox *x, *y, *range, *weapons, *heals, *armors, *lights, *mediums, *heavies, *collect, *kill;
    QGroupBox *fld, *enems, *items;
    QGridLayout *fldlt, *enemslt, *itemslt;
    QPushButton *start;

public:
    StartGameDialog(QWidget *parent, const Qt::WindowFlags &f);

signals:
    void generate(Vec2D v, int collect, int kill, int range,
                  int heals, int armors, int weapons, int lights, int mediums, int heavies);
};


#endif //STARTGAMEDIALOG_H
