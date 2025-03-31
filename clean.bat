@echo off

echo Press any key to clean...
pause >nul

rmdir /s /q .cache
rmdir /s /q bin
rmdir /s /q build
del /s compile_commands.json

echo Cleaned build residue

pause >nul
