#pragma once

#include <QWidget>

class Hero;
namespace Ui { class Location; }

class Location : public QWidget {
    Q_OBJECT
public:
    explicit Location(QWidget *parent = nullptr);

    enum Type {
        Empty,
        Town,
        Capital,
        Road,
        Resource
    };

    void setName(const QString &name) { m_name = name; }
    QString name() const { return m_name; }

    void setFraction(const int fraction) { m_fraction = fraction; }
    int fraction() const { return m_fraction; }

    void setType(const int type) { m_type = type; }
    int type() const { return m_type; }

    void setPlayer(const int player) { m_player = player;}
    int player() const { return m_player; }

private:
    Ui::Location *ui;

    QString m_name;
    int m_fraction;
    int m_type;
    int m_player;

    Hero *hero;
};
