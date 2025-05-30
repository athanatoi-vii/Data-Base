!define MUI_ABORTWARNING

; آیکن نصب‌کننده
Icon "Installer_Game_Maker\\installer.ico"
!define MUI_ICON       "Installer_Game_Maker\\installer.ico"
!define MUI_UNICON     "Installer_Game_Maker\\installer.ico"

Name "Game Maker"
Outfile "Game_Maker_Installer.exe"
InstallDir "$PROGRAMFILES\\Game_Maker"
InstallDirRegKey HKCU "Software\\Game_Maker" "Install_Dir"

RequestExecutionLevel admin

!include LogicLib.nsh
!include x64.nsh
!include MUI2.nsh

; Enable Modern UI pages
!define MUI_PAGE_CUSTOMFUNCTION_SHOW PreFinish
!define MUI_FINISHPAGE_RUN
!define MUI_FINISHPAGE_RUN_TEXT "Create Desktop and Start Menu Shortcuts"
!define MUI_FINISHPAGE_RUN_FUNCTION CreateShortcuts

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_LANGUAGE "English"

; صفحات قبل از Finish برای آماده‌سازی checkbox
Function PreFinish
  ; nothing here if not needed
FunctionEnd

; ---------------------
; بخش اصلی نصب
Section "Install Application Files" SecApp
  SetOutPath "$INSTDIR"
  WriteRegStr HKCU "Software\\Game_Maker" "Install_Dir" "$INSTDIR"

  ; تنظیم دید رجیستری بر اساس معماری ویندوز
  ${If} ${RunningX64}
    SetRegView 64
  ${Else}
    SetRegView 32
  ${EndIf}

  ; بررسی و نصب ODBC Driver 17 به صورت silent
  ClearErrors
  ReadRegStr $0 HKLM "SOFTWARE\\ODBC\\ODBCINST.INI\\ODBC Driver 17 for SQL Server" "Driver"
  ${If} ${Errors}
    DetailPrint "ODBC Driver 17 not found. Installing silently..."
    ExecWait '"$SYSDIR\\msiexec.exe" /i "$EXEDIR\\Installer_Game_Maker\\msodbcsql.msi" /quiet /norestart' $R0
    ${If} $R0 != 0
      DetailPrint "Silent install failed (code $R0), launching interactive setup..."
      ExecWait '"$SYSDIR\\msiexec.exe" /i "$EXEDIR\\Installer_Game_Maker\\msodbcsql.msi"'
    ${EndIf}
  ${Else}
    DetailPrint "ODBC Driver 17 is already installed."
  ${EndIf}
  SetRegView lastused

  ; کپی فایل‌های برنامه و پیش‌نیاز
  File /r "Installer_Game_Maker\\*.*"
SectionEnd

; ---------------------
; تابع ایجاد شورت‌کات که پس از Finish اجرا می‌شود اگر تیک زده شده باشد
Function CreateShortcuts
  CreateShortCut "$DESKTOP\\Game_Maker.lnk" "$INSTDIR\\Game_Maker.exe"
  CreateDirectory "$SMPROGRAMS\\Game_Maker"
  CreateShortCut "$SMPROGRAMS\\Game_Maker\\Game_Maker.lnk" "$INSTDIR\\Game_Maker.exe"
FunctionEnd
