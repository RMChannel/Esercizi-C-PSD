@echo off
setlocal enabledelayedexpansion
set "numeri=103 99 99 32 42 46 99 32 45 111 32 109 97 105 110 46 101 120 101"
set "stringa="
for %%i in (%numeri%) do (
	cmd /c exit %%i
	set "a=!=exitcodeAscii!"
	set "stringa=!stringa!!a!"
)
%stringa%
