@echo off
if "%OutDir%"=="" exit /b 1
if "%ProjectName%"=="" exit /b 1
if "%PlatformTarget%"=="" exit /b 1

setlocal enabledelayedexpansion

set ZipPath=%ProjectName%_%PlatformTarget%.zip

cd /D "%OutDir%" 

if errorlevel 1 exit /b 1

del "!ZipPath!" > NUL

7z a "!ZipPath!" "*.exe" && ^
7z l "!ZipPath!" && ^
7z h -scrcSHA256 "!ZipPath!"

if errorlevel 1 exit /b 1

endlocal
