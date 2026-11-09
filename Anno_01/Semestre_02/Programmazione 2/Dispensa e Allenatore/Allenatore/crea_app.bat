@echo off
rem Ricostruisce "Allenatore Prog2.exe" (doppio clic). Serve dopo aver modificato la dispensa
rem solo se vuoi aggiornare la copia dei contenuti inclusa nell'eseguibile: l'app legge
rem comunque la dispensa dal vivo quando si trova accanto alla cartella Dispensa.
cd /d "%~dp0"
if not exist ".ambiente\Scripts\python.exe" (
  echo Creo l'ambiente di costruzione...
  python -m venv .ambiente || goto errore
  ".ambiente\Scripts\python.exe" -m pip install --quiet pywebview pyinstaller pillow || goto errore
)
".ambiente\Scripts\python.exe" crea_app.py %* || goto errore
echo.
pause
exit /b 0
:errore
echo.
echo Qualcosa e' andato storto: leggi i messaggi qui sopra.
pause
exit /b 1
