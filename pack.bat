@echo off
if not defined OutDir exit /b 1
if not defined ProjectName exit /b 1
if not defined PlatformTarget exit /b 1
if not defined BuildVersion echo warning: BuildVersion is not defined >&2

setlocal enabledelayedexpansion

set ZipName=%ProjectName%_
if defined BuildVersion set ZipName=!ZipName!%BuildVersion%_
set ZipName=!ZipName!%PlatformTarget%.zip

cd /D "%OutDir%" 

if errorlevel 1 exit /b 1

del "!ZipName!" > NUL

7z a "!ZipName!" "*.exe" && ^
7z l "!ZipName!" && ^
7z h -scrcSHA256 "!ZipName!" "*.exe"

if errorlevel 1 exit /b 1

endlocal
