#include "location.h"

#include <ui_location.h>

Location::Location(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Location())
    , m_name("Uiuiui")
{

    ui->setupUi(this);

    ui->name->setText(name());
    ui->name->setDisabled(true);
}
