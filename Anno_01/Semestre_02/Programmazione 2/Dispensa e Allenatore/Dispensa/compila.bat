@echo off
REM Compila dispensa e soluzioni, in versione light e dark (doppio clic su questo file).
set PATH=%LOCALAPPDATA%\Programs\MiKTeX\miktex\bin\x64;%PATH%
cd /d "%~dp0"
for %%f in (dispensa-light dispensa-dark soluzioni-light soluzioni-dark) do (
  pdflatex -interaction=nonstopmode %%f.tex >nul
  pdflatex -interaction=nonstopmode %%f.tex >nul
)
del /q *.aux *.out *.toc 2>nul
echo Fatto: dispensa-light.pdf, dispensa-dark.pdf, soluzioni-light.pdf, soluzioni-dark.pdf
pause
