#include "location.h"

#include <ui_location.h>

Location::Location(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Location())
{

    ui->setupUi(this);

    ui->name->setText("");
    ui->name->setDisabled(true);
}
