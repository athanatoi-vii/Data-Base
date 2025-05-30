#ifndef C_L_LE_ADD_H
#define C_L_LE_ADD_H

#include <QWidget>

class C_L_LE_Add : public QWidget
{
    Q_OBJECT
public:
    explicit C_L_LE_Add(QWidget *parent = nullptr);
    ~C_L_LE_Add();
    void Set_Text_L(QString S);
    void Set_Format_LE(QString S);
    void Set_Text_LE(QString S);
    bool Is_Empty();
    class QString Get_Text_LE();

    class QLineEdit *LE;
    class QLabel *L;
private:
    class QHBoxLayout *HL;
};

#endif
