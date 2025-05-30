#include "window.h"
#include "ui_window.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <C_L_LE_Add.h>
#include <QTimer>

Window::~Window()
{
    delete ui;
}

Window::Window(QWidget *parent): QMainWindow(parent), ui(new Ui::Window)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Icon/M:/Picture/Back Grand/Data Base.png"));
    this->setWindowTitle("Data Base");

    ui->LE_Search_Member->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]{50}"), this));
    ui->LE_Search_Member->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 2px; padding: 1px; }");

    ui->PB_OK->hide();
    ui->PB_Save->hide();


    // Local Data Base
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString dsn = QString("Driver={SQL Server}; Server=IVAR; Database=Game Maker; Trusted_Connection=yes;");
    db.setDatabaseName(dsn);
    */

    // Server Data Base
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString server   = "game-maker-db-server-qt.database.windows.net";
    QString database = "Game Maker";
    QString username = "ivar.vii.7";
    QString password = "01001001_Dbgame_x";
    QString connectionString = QString("Driver={ODBC Driver 17 for SQL Server};"
                                       "Server=" + server + ";"
                                       "Database=" + database + ";"
                                       "Uid=" + username + ";"
                                       "Pwd=" + password + ";"
                                       "Encrypt=yes;"
                                       "TrustServerCertificate=no;"
                                       "Connection Timeout=30;");
    db.setDatabaseName(connectionString);
    if(!db.open())
    {
        QMessageBox::warning(this, "Connection", "No connect to data base: \n" + db.lastError().text());
        QTimer::singleShot(0, qApp, SLOT(quit()));
        return;
    }


    ui->TV_Table_Veiw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->TV_Table_Veiw->horizontalHeader()->setStretchLastSection(true);

    int DH = ui->TV_Table_Veiw->verticalHeader()->defaultSectionSize();
    ui->TV_Table_Veiw->verticalHeader()->setDefaultSectionSize(DH * 1.5);

    set_Table_view(ui->CB_Select_Table->currentText());
}

void Window::set_Table_view(QString S)
{
    QSqlQuery Query;
    QString SQ = "SELECT * FROM [dbo].[" + S + "]";
    Query.exec(SQ);
    Query_Model = new QSqlQueryModel(this);
    Query_Model->setQuery(Query);

    ui->TV_Table_Veiw->setModel(Query_Model);
}

void Window::on_CB_Select_Table_activated(const QString &arg1)
{
    if(Add_Menu)
    {
        Add_Menu = false;
        ui->PB_OK->hide();
        deleleMenu();
    }
    else if(Edit_Menu)
    {
        Edit_Menu = false;
        ui->PB_Save->hide();
        Index = QModelIndex();
        deleleMenu();
    }

    if(arg1 == "Department")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Department: ");
        ui->CB_Select_Search->addItem("Search Name Department: ");
        S_Row_Table_1 = "Department Code";
        S_Row_Table_2 = "Department Name";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Member")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Member: ");
        ui->CB_Select_Search->addItem("Search Name Member: ");
        S_Row_Table_1 = "Member Code";
        S_Row_Table_2 = "Name";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
        ui->CB_Filter->addItem("Member with more one task in project (GBM)");
        ui->CB_Filter->addItem("Member with skill in tools (GBM)");
    }
    else if (arg1 == "Member Mobil")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Member: ");
        S_Row_Table_1 = "Member Code";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Assigned")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Member: ");
        ui->CB_Select_Search->addItem("Search Code Project: ");
        S_Row_Table_1 = "Member Code";
        S_Row_Table_2 = "Project Code";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Project")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Project: ");
        ui->CB_Select_Search->addItem("Search Name Project: ");
        S_Row_Table_1 = "Project Code";
        S_Row_Table_2 = "Project Name";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Project Member")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Project: ");
        ui->CB_Select_Search->addItem("Search Code Member: ");
        S_Row_Table_1 = "Project Code";
        S_Row_Table_2 = "Member Code";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Tool")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Tool: ");
        ui->CB_Select_Search->addItem("Search Name Tool: ");
        S_Row_Table_1 = "Tool Code";
        S_Row_Table_2 = "Tool Name";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Skill")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Member: ");
        ui->CB_Select_Search->addItem("Search Code Tool: ");
        S_Row_Table_1 = "Member Code";
        S_Row_Table_2 = "Tool Code";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Task")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Task: ");
        ui->CB_Select_Search->addItem("Search Code Project: ");
        ui->CB_Select_Search->addItem("Search Code Member: ");
        S_Row_Table_1 = "Number";
        S_Row_Table_2 = "Project Code";
        S_Row_Table_3 = "Member Code";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Platform")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Platform: ");
        ui->CB_Select_Search->addItem("Search Name Platform: ");
        S_Row_Table_1 = "Platform Code";
        S_Row_Table_2 = "Name Platform";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "Project Platform")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Project: ");
        ui->CB_Select_Search->addItem("Search Code Platform: ");
        S_Row_Table_1 = "Project Code";
        S_Row_Table_2 = "Platform Code";
        ui->PB_Add->show();
        ui->PB_Delete->show();
        ui->PB_Edit->show();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "PC")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Platform: ");
        S_Row_Table_1 = "Platform Code";
        ui->PB_Add->hide();
        ui->PB_Delete->hide();
        ui->PB_Edit->hide();
        ui->PB_OK->hide();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "PS")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Platform: ");
        S_Row_Table_1 = "Platform Code";
        ui->PB_Add->hide();
        ui->PB_Delete->hide();
        ui->PB_Edit->hide();
        ui->PB_OK->hide();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "XBOX")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Platform: ");
        S_Row_Table_1 = "Platform Code";
        ui->PB_Add->hide();
        ui->PB_Delete->hide();
        ui->PB_Edit->hide();
        ui->PB_OK->hide();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else if (arg1 == "NS")
    {
        ui->CB_Select_Search->clear();
        ui->CB_Select_Search->addItem("Search Code Platform: ");
        S_Row_Table_1 = "Platform Code";
        ui->PB_Add->hide();
        ui->PB_Delete->hide();
        ui->PB_Edit->hide();
        ui->PB_OK->hide();
        ui->CB_Filter->clear();
        ui->CB_Filter->addItem("None");
    }
    else
    {
        return;
    }

    ui->LE_Search_Member->clear();
    set_Table_view(arg1);
}

void Window::on_LE_Search_Member_textEdited(const QString &arg1)
{
    QSqlQuery Query;
    QString SQ;
    int N = ui->CB_Select_Search->currentIndex();
    if(N == 0)
    {
        SQ = "SELECT * FROM [dbo].[" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_1 + "] LIKE '%" + arg1 + "%'";
    }
    else if (N == 1)
    {
        SQ = "SELECT * FROM [dbo].[" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_2 + "] LIKE '%" + arg1 + "%'";
    }
    else
    {
        SQ = "SELECT * FROM [dbo].[" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_3 + "] LIKE '%" + arg1 + "%'";
    }
    Query.exec(SQ);
    Query_Model = new QSqlQueryModel(this);
    Query_Model->setQuery(Query);
    ui->TV_Table_Veiw->setModel(Query_Model);
}

void Window::on_PB_Refresh_clicked()
{
    if(ui->LE_Search_Member->text().isEmpty())
    {
        set_Table_view(ui->CB_Select_Table->currentText());
    }
    else
    {
        on_LE_Search_Member_textEdited(ui->LE_Search_Member->text());
    }

    if(Menu_Refresh)
    {
        if(Add_Menu)
        {
            Add_Menu = false;
            ui->PB_OK->hide();
            deleleMenu();
        }
        else if(Edit_Menu)
        {
            Edit_Menu = false;
            ui->PB_Save->hide();
            Index = QModelIndex();
            deleleMenu();
        }
    }
    else
    {
        Menu_Refresh = true;
    }
}

void Window::on_PB_Add_clicked()
{
    if((!Add_Menu) && (!Edit_Menu))
    {
        Add_Menu = true;
        ui->PB_OK->show();
        Show_C_L_LE_Add();
    }
    else if ((Add_Menu) && (!Edit_Menu))
    {
        ui->PB_OK->hide();
        Add_Menu = false;
        deleleMenu();
    }
    else
    {
        return;
    }
}

void Window::on_PB_OK_clicked()
{
    QString SE = ui->CB_Select_Table->currentText();
    QSqlQuery Query;

    if(SE == "Department")
    {
        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Department] ([Department Code], [Department Name]) VALUES (:C, :N)");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
    }
    else if (SE == "Member")
    {
        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();
        QString L = LName->Get_Text_LE();
        QString G = Gmail->Get_Text_LE();
        QString D = FCode->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty() || G.isEmpty() || D.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Member] ([Member Code], Name, [Last Name], Gemail, [Department Code]) VALUES (:C, :N, :L, :G, :D)");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":L", L);
        Query.bindValue(":G", G);
        Query.bindValue(":D", D);
    }
    else if (SE == "Member Mobil")
    {
        QString C = Code->Get_Text_LE();
        QString M = Mobile->Get_Text_LE();

        if (C.isEmpty() || M.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Member Mobil] ([Member Code], [Mobil]) VALUES (:C, :M)");
        Query.bindValue(":C", C);
        Query.bindValue(":M", M);
    }
    else if (SE == "Assigned")
    {
        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();
        QString S = Text->Get_Text_LE();
        QString T = Time->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Assigned] ([Member Code], [Project Code], Status, [Time Line]) VALUES (:C, :FC, :S, :T)");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
        Query.bindValue(":S", S);
        Query.bindValue(":T", T);
    }
    else if (SE == "Project")
    {
        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();
        QString T = Time->Get_Text_LE();

        if (C.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Project] ([Project Code], [Project Name], [Start Time]) VALUES (:C, :N, :T)");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":T", T);
    }
    else if (SE == "Project Member")
    {
        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();
        QString R = Text->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Project Member] ([Project Code], [Member Code], Role) VALUES (:C, :FC, :R)");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
        Query.bindValue(":R", R);
    }
    else if (SE == "Tool")
    {
        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();
        QString V = Text->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Tool] ([Tool Code], [Tool Name], Version) VALUES (:C, :N, :V)");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":V", V);
    }
    else if (SE == "Skill")
    {
        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Skill] ([Member Code], [Tool Code]) VALUES (:C, :FC)");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
    }
    else if (SE == "Task")
    {
        QString NC = NCode->Get_Text_LE();
        QString C = Code->Get_Text_LE();
        QString TA = Name->Get_Text_LE();
        QString D = Text->Get_Text_LE();
        QString T = Time->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();

        if (C.isEmpty() || NC.isEmpty() || TA.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Task] (Number, [Project Code], Titel, Description, [End Time Task], [Member Code]) VALUES (:NC, :C, :TA, :D, :T, :FC)");
        Query.bindValue(":NC", NC);
        Query.bindValue(":C", C);
        Query.bindValue(":TA", TA);
        Query.bindValue(":D", D);
        Query.bindValue(":T", T);
        Query.bindValue(":FC", FC);
    }
    else if (SE == "Platform")
    {
        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Platform] ([Platform Code], [Name Platform]) VALUES (:C, :N)");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
    }
    else if (SE == "Project Platform")
    {
        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("INSERT INTO [dbo].[Project Platform] ([Project Code], [Platform Code]) VALUES (:C, :FC)");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
    }
    else
    {
        return;
    }

    if(!Query.exec())
    {
        QString errorText = Query.lastError().text();

        if (errorText.contains("duplicate", Qt::CaseInsensitive) ||
            errorText.contains("PRIMARY KEY", Qt::CaseInsensitive) ||
            errorText.contains("UNIQUE constraint", Qt::CaseInsensitive))
        {

            QMessageBox::warning(this, "Duplicate Entry", "This value already exists and must be unique.");

        }
        else if (errorText.contains("FOREIGN KEY", Qt::CaseInsensitive))
        {
            QMessageBox::warning(this, "Invalid Reference", "The referenced value does not exist (foreign key violation).");
        }
    }

    if(ui->LE_Search_Member->text().isEmpty())
    {
        set_Table_view(ui->CB_Select_Table->currentText());
    }
    else
    {
        on_LE_Search_Member_textEdited(ui->LE_Search_Member->text());
    }
}

void Window::on_PB_Delete_clicked()
{
    if (!Index.isValid())
    {
        QMessageBox::information(this, "No Selection", "Please select a row to delete.");
        return;
    }

    int row = Index.row();

    QModelIndex I0 = ui->TV_Table_Veiw->model()->index(row, 0);
    QVariant C = ui->TV_Table_Veiw->model()->data(I0);

    int confirm = QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this row?", QMessageBox::Yes | QMessageBox::No);

    if (confirm != QMessageBox::Yes)
    {
        return;
    }

    QSqlQuery Query;

    QString T = ui->CB_Select_Table->currentText();
    if(T == "Department" || T == "Member" || T == "Project" || T == "Tool" || T == "Task" || T == "Platform")
    {
        Query.prepare("DELETE FROM [" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_1 + "] = :C");
        Query.bindValue(":C", C);
    }
    else
    {
        if(T == "Member Mobil")
        {
            QModelIndex I1 = ui->TV_Table_Veiw->model()->index(row, 1);
            QVariant M = ui->TV_Table_Veiw->model()->data(I1);

            Query.prepare("DELETE FROM [" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_1 + "] = :C AND Mobil = :M");
            Query.bindValue(":C", C);
            Query.bindValue(":M", M);
        }
        else if(T == "Assigned")
        {
            QModelIndex I1 = ui->TV_Table_Veiw->model()->index(row, 1);
            QVariant FC = ui->TV_Table_Veiw->model()->data(I1);
            QModelIndex I2 = ui->TV_Table_Veiw->model()->index(row, 2);
            QVariant S = ui->TV_Table_Veiw->model()->data(I2);
            QModelIndex I3 = ui->TV_Table_Veiw->model()->index(row, 3);
            QVariant T = ui->TV_Table_Veiw->model()->data(I3);

            Query.prepare("DELETE FROM [" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_1 + "] = :C AND [" + S_Row_Table_2 + "] = :FC AND Status = :S AND [Time Line] = :T");
            Query.bindValue(":C", C);
            Query.bindValue(":FC", FC);
            Query.bindValue(":S", S);
            Query.bindValue(":T", T);
        }
        else if (T == "Project Member")
        {
            QModelIndex I1 = ui->TV_Table_Veiw->model()->index(row, 1);
            QVariant FC = ui->TV_Table_Veiw->model()->data(I1);
            QModelIndex I2 = ui->TV_Table_Veiw->model()->index(row, 2);
            QVariant R = ui->TV_Table_Veiw->model()->data(I2);

            Query.prepare("DELETE FROM [" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_1 + "] = :C AND [" + S_Row_Table_2 + "] = :FC AND Role = :R");
            Query.bindValue(":C", C);
            Query.bindValue(":FC", FC);
            Query.bindValue(":R", R);
        }
        else if (T == "Skill")
        {
            QModelIndex I1 = ui->TV_Table_Veiw->model()->index(row, 1);
            QVariant FC = ui->TV_Table_Veiw->model()->data(I1);

            Query.prepare("DELETE FROM [" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_1 + "] = :C AND [" + S_Row_Table_2 + "] = :FC");
            Query.bindValue(":C", C);
            Query.bindValue(":FC", FC);
        }
        else if (T == "Project Platform")
        {
            QModelIndex I1 = ui->TV_Table_Veiw->model()->index(row, 1);
            QVariant FC = ui->TV_Table_Veiw->model()->data(I1);

            Query.prepare("DELETE FROM [" + ui->CB_Select_Table->currentText() + "] WHERE [" + S_Row_Table_1 + "] = :C AND [" + S_Row_Table_2 + "] = :FC");
            Query.bindValue(":C", C);
            Query.bindValue(":FC", FC);
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to delete");
        }
    }

    if (!Query.exec())
    {
        QMessageBox::critical(this, "Error", "Failed to delete:\n" + Query.lastError().text());
        return;
    }

    Menu_Refresh = false;
    on_PB_Refresh_clicked();
}

void Window::on_CB_Select_Search_activated(int index)
{
    Q_UNUSED(index);

    ui->LE_Search_Member->clear();
    on_PB_Refresh_clicked();
}

void Window::deleleMenu()
{
    if(Code)
    {
        delete Code;
        Code = nullptr;
    }
    if(Name)
    {
        delete Name;
        Name = nullptr;
    }
    if(LName)
    {
        delete LName;
        LName = nullptr;
    }
    if(Gmail)
    {
        delete Gmail;
        Gmail = nullptr;
    }
    if(FCode)
    {
        delete FCode;
        FCode = nullptr;
    }
    if(Mobile)
    {
        delete Mobile;
        Mobile = nullptr;
    }
    if(Text)
    {
        delete Text;
        Text = nullptr;
    }
    if(Time)
    {
        delete Time;
        Time = nullptr;
    }
    if(NCode)
    {
        delete NCode;
        NCode = nullptr;
    }
}

void Window::on_PB_Edit_clicked()
{
    if (Index.isValid())
    {
        QString SE = ui->CB_Select_Table->currentText();
        int row = Index.row();

        if(Update_Edit)
        {
            if((!Add_Menu) && (!Edit_Menu))
            {
                Edit_Menu = true;
                ui->PB_Save->show();
                Show_C_L_LE_Add();
            }
            else if ((!Add_Menu) && (Edit_Menu))
            {
                Edit_Menu = false;
                ui->PB_Save->hide();
                Index = QModelIndex();
                deleleMenu();
            }
            else
            {
                return;
            }
        }
        else
        {
            Update_Edit = true;
        }

        if(SE == "Department")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();

            if(Code != nullptr && Name != nullptr)
            {
                Code->Set_Text_LE(v0);
                Name->Set_Text_LE(v1);
            }
        }
        else if (SE == "Member")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();
            QString v2 = Query_Model->data(Query_Model->index(row, 2)).toString();
            QString v3 = Query_Model->data(Query_Model->index(row, 3)).toString();
            QString v4 = Query_Model->data(Query_Model->index(row, 4)).toString();

            if(Code != nullptr && Name != nullptr && LName != nullptr && Gmail != nullptr && FCode != nullptr)
            {
                Code->Set_Text_LE(v0);
                Name->Set_Text_LE(v1);
                LName->Set_Text_LE(v2);
                Gmail->Set_Text_LE(v3);
                FCode->Set_Text_LE(v4);
            }
        }
        else if (SE == "Member Mobil")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();

            if(Code != nullptr && Mobile != nullptr)
            {
                Code->Set_Text_LE(v0);
                Mobile->Set_Text_LE(v1);
            }
        }
        else if (SE == "Assigned")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();
            QString v2 = Query_Model->data(Query_Model->index(row, 2)).toString();
            QString v3 = Query_Model->data(Query_Model->index(row, 3)).toString();

            if(Code != nullptr && FCode != nullptr && Text != nullptr && Time != nullptr)
            {
                Code->Set_Text_LE(v0);
                FCode->Set_Text_LE(v1);
                Text->Set_Text_LE(v2);
                Time->Set_Text_LE(v3);
            }
        }
        else if (SE == "Project")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();
            QString v2 = Query_Model->data(Query_Model->index(row, 2)).toString();

            if(Code != nullptr && Name != nullptr && Time != nullptr)
            {
                Code->Set_Text_LE(v0);
                Name->Set_Text_LE(v1);
                Time->Set_Text_LE(v2);
            }
        }
        else if (SE == "Project Member")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();
            QString v2 = Query_Model->data(Query_Model->index(row, 2)).toString();

            if(Code != nullptr && FCode != nullptr && Text != nullptr)
            {
                Code->Set_Text_LE(v0);
                FCode->Set_Text_LE(v1);
                Text->Set_Text_LE(v2);
            }
        }
        else if (SE == "Tool")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();
            QString v2 = Query_Model->data(Query_Model->index(row, 2)).toString();

            if(Code != nullptr && Name != nullptr && Text != nullptr)
            {
                Code->Set_Text_LE(v0);
                Name->Set_Text_LE(v1);
                Text->Set_Text_LE(v2);
            }
        }
        else if (SE == "Skill")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();

            if(Code != nullptr && FCode != nullptr)
            {
                Code->Set_Text_LE(v0);
                FCode->Set_Text_LE(v1);
            }
        }
        else if (SE == "Task")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();
            QString v2 = Query_Model->data(Query_Model->index(row, 2)).toString();
            QString v3 = Query_Model->data(Query_Model->index(row, 3)).toString();
            QString v4 = Query_Model->data(Query_Model->index(row, 4)).toString();
            QString v5 = Query_Model->data(Query_Model->index(row, 5)).toString();

            if(NCode != nullptr && Code != nullptr && FCode != nullptr && Name != nullptr && Text != nullptr && Time != nullptr)
            {
                NCode->Set_Text_LE(v0);
                Code->Set_Text_LE(v1);
                FCode->Set_Text_LE(v2);
                Name->Set_Text_LE(v3);
                Text->Set_Text_LE(v4);
                Time->Set_Text_LE(v5);
            }
        }
        else if (SE == "Platform")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();

            if(Code != nullptr && Name != nullptr)
            {
                Code->Set_Text_LE(v0);
                Name->Set_Text_LE(v1);
            }
        }
        else if (SE == "Project Platform")
        {
            QString v0 = Query_Model->data(Query_Model->index(row, 0)).toString();
            QString v1 = Query_Model->data(Query_Model->index(row, 1)).toString();

            if(Code != nullptr && FCode != nullptr)
            {
                Code->Set_Text_LE(v0);
                FCode->Set_Text_LE(v1);
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        QMessageBox::information(this, "No Selection", "Please select a row to edit.");
    }
}

void Window::on_PB_Save_clicked()
{
    QModelIndex I0 = ui->TV_Table_Veiw->model()->index(Index.row(), 0);
    QVariant K = ui->TV_Table_Veiw->model()->data(I0);

    int confirm = QMessageBox::question(this, "Confirm Edit", "Are you sure you want to Edit this row?", QMessageBox::Yes | QMessageBox::No);

    if (confirm != QMessageBox::Yes)
    {
        return;
    }

    QSqlQuery Query;
    QString SE = ui->CB_Select_Table->currentText();

    if(SE == "Department")
    {
        if (Code == nullptr || Name == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Department] SET [Department Code] = :C, [Department Name] = :N WHERE [Department Code] = :I");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":I", K);
    }
    else if (SE == "Member")
    {
        if (Code == nullptr || Name == nullptr || LName == nullptr || Gmail == nullptr || FCode == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();
        QString L = LName->Get_Text_LE();
        QString G = Gmail->Get_Text_LE();
        QString D = FCode->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty() || G.isEmpty() || D.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Member] SET [Member Code] = :C, Name = :N, [Last Name] = :L, Gemail = :G, [Department Code] = :D WHERE [Member Code] = :K");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":L", L);
        Query.bindValue(":G", G);
        Query.bindValue(":D", D);
        Query.bindValue(":K", K);
    }
    else if (SE == "Member Mobil")
    {
        QModelIndex I1 = ui->TV_Table_Veiw->model()->index(Index.row(), 1);
        QVariant K1 = ui->TV_Table_Veiw->model()->data(I1);

        if (Code == nullptr || Mobile == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString M = Mobile->Get_Text_LE();

        if (C.isEmpty() || M.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Member Mobil] SET [Member Code] = :C, Mobil = :M WHERE [Member Code] = :K AND Mobil = :K1");
        Query.bindValue(":C", C);
        Query.bindValue(":M", M);
        Query.bindValue(":K", K);
        Query.bindValue(":K1", K1);
    }
    else if (SE == "Assigned")
    {
        QModelIndex I1 = ui->TV_Table_Veiw->model()->index(Index.row(), 1);
        QVariant K1 = ui->TV_Table_Veiw->model()->data(I1);
        QModelIndex I2 = ui->TV_Table_Veiw->model()->index(Index.row(), 2);
        QVariant K2 = ui->TV_Table_Veiw->model()->data(I2);
        QModelIndex I3 = ui->TV_Table_Veiw->model()->index(Index.row(), 3);
        QVariant K3 = ui->TV_Table_Veiw->model()->data(I3);

        if (Code == nullptr || FCode == nullptr || Text == nullptr || Time == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();
        QString S = Text->Get_Text_LE();
        QString T = Time->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Assigned] SET [Member Code] = :C, [Project Code] = :FC, Status = :S, [Time Line] = :T WHERE [Member Code] = :K AND [Project Code] = :K1 AND Status = :K2 AND [Time Line] = :K3");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
        Query.bindValue(":S", S);
        Query.bindValue(":T", T);
        Query.bindValue(":K", K);
        Query.bindValue(":K1", K1);
        Query.bindValue(":K2", K2);
        Query.bindValue(":K3", K3);
    }
    else if (SE == "Project")
    {
        if (Code == nullptr || Name == nullptr || Time == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();
        QString T = Time->Get_Text_LE();

        if (C.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Project] SET [Project Code] = :C, [Project Name] = :N, [Start Time] = :T WHERE [Project Code] = :K");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":T", T);
        Query.bindValue(":K", K);
    }
    else if (SE == "Project Member")
    {
        QModelIndex I1 = ui->TV_Table_Veiw->model()->index(Index.row(), 1);
        QVariant K1 = ui->TV_Table_Veiw->model()->data(I1);
        QModelIndex I2 = ui->TV_Table_Veiw->model()->index(Index.row(), 2);
        QVariant K2 = ui->TV_Table_Veiw->model()->data(I2);

        if (Code == nullptr || FCode == nullptr || Text == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();
        QString R = Text->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Project Member] SET [Project Code] = :C, [Member Code] = :FC, Role = :R WHERE [Project Code] = :K AND [Member Code] = :K1 AND Role = :K2");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
        Query.bindValue(":R", R);
        Query.bindValue(":K", K);
        Query.bindValue(":K1", K1);
        Query.bindValue(":K2", K2);
    }
    else if (SE == "Tool")
    {
        if (Code == nullptr || Name == nullptr || Text == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();
        QString V = Text->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Tool] SET [Tool Code] = :C, [Tool Name] = :N, Version = :V WHERE [Tool Code] = :K");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":V", V);
        Query.bindValue(":K", K);
    }
    else if (SE == "Skill")
    {
        QModelIndex I1 = ui->TV_Table_Veiw->model()->index(Index.row(), 1);
        QVariant K1 = ui->TV_Table_Veiw->model()->data(I1);

        if (Code == nullptr || FCode == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Skill] SET [Member Code] = :C, [Tool Code] = :FC WHERE [Member Code] = :K AND [Tool Code] = :K1");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
        Query.bindValue(":K", K);
        Query.bindValue(":K1", K1);
    }
    else if (SE == "Task")
    {
        if (NCode == nullptr || Code == nullptr || FCode == nullptr || Name == nullptr || Text == nullptr || Time == nullptr)
        {
            return;
        }

        QString NC = NCode->Get_Text_LE();
        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();
        QString TA = Name->Get_Text_LE();
        QString D = Text->Get_Text_LE();
        QString T = Time->Get_Text_LE();    

        if (C.isEmpty() || NC.isEmpty() || TA.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Task] SET Number = :NC, [Project Code] = :C, [Member Code] = :FC, Titel = :TA, Description = :D, [End Time Task] = :T WHERE Number = :K");
        Query.bindValue(":NC", NC);
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
        Query.bindValue(":TA", TA);
        Query.bindValue(":D", D);
        Query.bindValue(":T", T);
        Query.bindValue(":K", K);
    }
    else if (SE == "Platform")
    {
        if (Code == nullptr || Name == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString N = Name->Get_Text_LE();

        if (C.isEmpty() || N.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Platform] SET [Platform Code] = :C, [Name Platform] = :N WHERE [Platform Code] = :K");
        Query.bindValue(":C", C);
        Query.bindValue(":N", N);
        Query.bindValue(":K", K);
    }
    else if (SE == "Project Platform")
    {
        QModelIndex I1 = ui->TV_Table_Veiw->model()->index(Index.row(), 1);
        QVariant K1 = ui->TV_Table_Veiw->model()->data(I1);

        if (Code == nullptr || FCode == nullptr)
        {
            return;
        }

        QString C = Code->Get_Text_LE();
        QString FC = FCode->Get_Text_LE();

        if (C.isEmpty() || FC.isEmpty())
        {
            QMessageBox::warning(this, "There is an empty line", "Please fill in the required fields");
            return;
        }

        Query.prepare("UPDATE [dbo].[Project Platform] SET [Project Code] = :C, [Platform Code] = :FC WHERE [Project Code] = :K AND [Platform Code] = :K1");
        Query.bindValue(":C", C);
        Query.bindValue(":FC", FC);
        Query.bindValue(":K", K);
        Query.bindValue(":K1", K1);
    }
    else
    {
        return;
    }

    if (Query.exec())
    {
        Menu_Refresh = false;
        on_PB_Refresh_clicked();
    }
    else
    {
        QMessageBox::warning(this, "Eror", "Eror: \n" + Query.lastError().text());
    }
}

void Window::Show_C_L_LE_Add()
{
    QString SE = ui->CB_Select_Table->currentText();

    if(SE == "Department")
    {
        Code = new C_L_LE_Add();
        Name = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        Name->Set_Text_L("Name: ");

        Code->Set_Format_LE("[0-9]{13}");
        Name->Set_Format_LE("[a-zA-Z ()-/]{50}");

        ui->P->addWidget(Code);
        ui->P->addWidget(Name);
    }
    else if (SE == "Member")
    {
        Code = new C_L_LE_Add();
        Name = new C_L_LE_Add();
        LName = new C_L_LE_Add();
        Gmail = new C_L_LE_Add();
        FCode = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        Name->Set_Text_L("Name: ");
        LName->Set_Text_L("Last Name: ");
        Gmail->Set_Text_L("Gmail: ");
        FCode->Set_Text_L("Department Code: ");

        Code->Set_Format_LE("[0-9]{13}");
        Name->Set_Format_LE("[a-zA-Z]{1,48}[ ]{2}");
        LName->Set_Format_LE("[a-zA-Z]{1,48}[ ]{2}");
        Gmail->Set_Format_LE("[a-zA-Z0-9.]{1,280}@[a-zA-Z0-9]{1,37}.[a-z]{2,3}");
        FCode->Set_Format_LE("[0-9]{13}");

        ui->P->addWidget(Code);
        ui->P->addWidget(Name);
        ui->P->addWidget(LName);
        ui->P->addWidget(Gmail);
        ui->P->addWidget(FCode);
    }
    else if (SE == "Member Mobil")
    {
        Code = new C_L_LE_Add();
        Mobile = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        Mobile->Set_Text_L("Mobile: ");

        Code->Set_Format_LE("[0-9]{13}");
        Mobile->Set_Format_LE("[0-9]{15}");

        ui->P->addWidget(Code);
        ui->P->addWidget(Mobile);
    }
    else if (SE == "Assigned")
    {
        Code = new C_L_LE_Add();
        FCode = new C_L_LE_Add();
        Text = new C_L_LE_Add();
        Time = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        FCode->Set_Text_L("Code: ");
        Text->Set_Text_L("Status: ");
        Time->Set_Text_L("Time line: ");

        Code->Set_Format_LE("[0-9]{13}");
        FCode->Set_Format_LE("[0-9]{13}");
        Text->Set_Format_LE("[a-zA-Z0-9 _-/()]{1,50}");
        Time->Set_Format_LE("[0-9]{2,4}/[0-9]{1,2}/[0-9]{1,2} [0-9]{1,2}:[0-9]{1,2}");
        Time->LE->setPlaceholderText("0000/00/00 00:00");

        ui->P->addWidget(Code);
        ui->P->addWidget(FCode);
        ui->P->addWidget(Text);
        ui->P->addWidget(Time);
    }
    else if (SE == "Project")
    {
        Code = new C_L_LE_Add();
        Name = new C_L_LE_Add();
        Time = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        Name->Set_Text_L("Name: ");
        Time->Set_Text_L("Time start: ");

        Code->Set_Format_LE("[0-9]{13}");
        Name->Set_Format_LE("[a-zA-Z0-9 ]{1,50}");
        Time->Set_Format_LE("[0-9]{2,4}/[0-9]{1,2}/[0-9]{1,2} [0-9]{1,2}:[0-9]{1,2}");
        Time->LE->setPlaceholderText("0000/00/00 00:00");

        ui->P->addWidget(Code);
        ui->P->addWidget(Name);
        ui->P->addWidget(Time);
    }
    else if (SE == "Project Member")
    {
        Code = new C_L_LE_Add();
        FCode = new C_L_LE_Add();
        Text = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        FCode->Set_Text_L("Code: ");
        Text->Set_Text_L("Role: ");

        Code->Set_Format_LE("[0-9]{13}");
        FCode->Set_Format_LE("[0-9]{13}");
        Text->Set_Format_LE("[a-zA-Z -_/()]{1,100}");

        ui->P->addWidget(Code);
        ui->P->addWidget(FCode);
        ui->P->addWidget(Text);
    }
    else if (SE == "Tool")
    {
        Code = new C_L_LE_Add();
        Name = new C_L_LE_Add();
        Text = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        Name->Set_Text_L("Name: ");
        Text->Set_Text_L("Version: ");

        Code->Set_Format_LE("[0-9]{13}");
        Name->Set_Format_LE("[a-zA-Z0-9 ]{1,50}");
        Text->Set_Format_LE("[0-9]{1,3}[.][0-9]{1,2}[.][0-9]{0,2}");
        Text->LE->setPlaceholderText("000.00.00");

        ui->P->addWidget(Code);
        ui->P->addWidget(Name);
        ui->P->addWidget(Text);
    }
    else if (SE == "Skill")
    {
        Code = new C_L_LE_Add();
        FCode = new C_L_LE_Add();

        Code->Set_Text_L("Code Member: ");
        FCode->Set_Text_L("Code Tool: ");

        Code->Set_Format_LE("[0-9]{13}");
        FCode->Set_Format_LE("[0-9]{13}");

        ui->P->addWidget(Code);
        ui->P->addWidget(FCode);
    }
    else if (SE == "Task")
    {
        NCode = new C_L_LE_Add();
        Code = new C_L_LE_Add();
        Name = new C_L_LE_Add();
        Text = new C_L_LE_Add();
        Time = new C_L_LE_Add();
        FCode = new C_L_LE_Add();

        NCode->Set_Text_L("Number: ");
        Code->Set_Text_L("P Code: ");
        FCode->Set_Text_L("M Code: ");
        Name->Set_Text_L("Titel: ");
        Text->Set_Text_L("Description: ");
        Time->Set_Text_L("End Time: ");

        NCode->Set_Format_LE("[0-9]{10}");
        Code->Set_Format_LE("[0-9]{13}");
        FCode->Set_Format_LE("[0-9]{13}");
        Name->Set_Format_LE("[a-zA-Z0-9 ]{1,100}");
        Text->LE->setMaxLength(1000);
        Time->Set_Format_LE("[0-9]{2,4}/[0-9]{1,2}/[0-9]{1,2} [0-9]{1,2}:[0-9]{1,2}");
        Time->LE->setPlaceholderText("0000/00/00 00:00");

        ui->P->addWidget(NCode);
        ui->P->addWidget(Code);
        ui->P->addWidget(FCode);
        ui->P->addWidget(Name);
        ui->P->addWidget(Text);
        ui->P->addWidget(Time);
    }
    else if (SE == "Platform")
    {
        Code = new C_L_LE_Add();
        Name = new C_L_LE_Add();

        Code->Set_Text_L("Code: ");
        Name->Set_Text_L("Name: ");

        Code->Set_Format_LE("[0-9]{13}");
        Name->Set_Format_LE("[a-zA-Z -]{1,100}");

        ui->P->addWidget(Code);
        ui->P->addWidget(Name);
    }
    else if (SE == "Project Platform")
    {
        Code = new C_L_LE_Add();
        FCode = new C_L_LE_Add();

        Code->Set_Text_L("Code Project: ");
        FCode->Set_Text_L("Code Platform: ");

        Code->Set_Format_LE("[0-9]{13}");
        FCode->Set_Format_LE("[0-9]{13}");

        ui->P->addWidget(Code);
        ui->P->addWidget(FCode);
    }
    else
    {
        return;
    }
}

void Window::on_TV_Table_Veiw_clicked(const QModelIndex &index)
{
    Index = index;
    if(Edit_Menu)
    {
        Update_Edit = false;
        on_PB_Edit_clicked();
    }
}

void Window::on_CB_Filter_activated(int index)
{
    if (index != 0)
    {
        ui->LE_Search_Member->clear();
    }

    int IE = ui->CB_Select_Table->currentIndex();
    QSqlQuery Query;
    QString SQ;

    switch (IE)
    {
    case 1:
        switch (index)
        {
        case 0:
            Menu_Refresh = false;
            on_PB_Refresh_clicked();
            break;
        case 1:
            SQ = "SELECT *, "
                 "  (SELECT COUNT(*) FROM Task WHERE Task.[Member Code] = Member.[Member Code]) AS TaskCount "
                 "FROM Member "
                 "WHERE [Member Code] IN "
                 "("
                 "  SELECT [Member Code] "
                 "  FROM Task "
                 "  GROUP BY [Member Code] "
                 "  HAVING COUNT(*) > 1"
                 ") "
                 "ORDER BY TaskCount DESC;";

            Query.exec(SQ);

            Query_Model = new QSqlQueryModel(this);
            Query_Model->setQuery(Query);

            break;
        case 2:
            SQ = "SELECT *, "
                 "  (SELECT COUNT(*) FROM Skill WHERE Skill.[Member Code] = Member.[Member Code]) AS SkillCount "
                 "FROM Member "
                 "WHERE [Member Code] IN "
                 "("
                 "  SELECT [Member Code] "
                 "  FROM Skill "
                 "  GROUP BY [Member Code] "
                 "  HAVING COUNT(*) >= 1"
                 ") "
                 "ORDER BY SkillCount DESC;";

            Query.exec(SQ);

            Query_Model = new QSqlQueryModel(this);
            Query_Model->setQuery(Query);

            break;
        }
    break;
    }

    ui->TV_Table_Veiw->setModel(Query_Model);
}
