#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QLabel>
#include <C_L_LE_Add.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void set_Table_view(QString S);

    void on_CB_Select_Table_activated(const QString &arg1);

    void on_LE_Search_Member_textEdited(const QString &arg1);

    void on_PB_Refresh_clicked();

    void on_PB_Add_clicked();

    void on_PB_OK_clicked();

    void on_PB_Delete_clicked();

    void on_CB_Select_Search_activated(int index);

    void deleleMenu();

    void on_PB_Save_clicked();

    void on_PB_Edit_clicked();

    void Show_C_L_LE_Add();

    void on_TV_Table_Veiw_clicked(const QModelIndex &index);

    void on_CB_Filter_activated(int index);

private:
    Ui::Window *ui;

    QSqlQueryModel *Query_Model;
    QModelIndex Index;

    QString S_Row_Table_1 = "Department Code";
    QString S_Row_Table_2 = "Department Name";
    QString S_Row_Table_3 = "";

    bool Add_Menu = false;
    bool Edit_Menu = false;
    bool Update_Edit = true;
    bool Menu_Refresh = true;

    C_L_LE_Add *Code = nullptr;
    C_L_LE_Add *Name = nullptr;
    C_L_LE_Add *LName = nullptr;
    C_L_LE_Add *Gmail = nullptr;
    C_L_LE_Add *FCode = nullptr;
    C_L_LE_Add *NCode = nullptr;
    C_L_LE_Add *Mobile = nullptr;
    C_L_LE_Add *Time = nullptr;
    C_L_LE_Add *Text = nullptr;
};
#endif
