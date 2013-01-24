@echo off
setlocal

rem To install ESC/Java on a new machine, change the following four
rem lines appropriately (replace <REPERTOIRE_TP>):
set ESCJAVA_ROOT=Z:\cours\omgl\validation\TP-EscJava-windows\windows\escjava
set JAVA=Z:\cours\omgl\validation\TP-EscJava-windows\windows\Java/JRE/1.2\bin\java.exe
set JAVA_STDLIB=Z:\cours\omgl\validation\TP-EscJava-windows\windows\Java\JRE\1.2\lib\rt.jar
set CLASSPATH=Z:\cours\omgl\validation\TP-EscJava-windows\windows\Java\JRE\1.2\ib\rt.jar

rem Some arguments to Simplify, passed via environment variables
if "%ESCJ_SIMPLIFY%"=="" set ESCJ_SIMPLIFY=%ESCJAVA_ROOT%\bin\Simplify.exe
if "%ESCJ_SIMPLIFY_ARGS%"=="" set ESCJ_SIMPLIFY_ARGS=-noprune -noplunge
if "%PROVER_KILL_TIME%"=="" set PROVER_KILL_TIME=300
if "%PROVER_CC_LIMIT%"=="" set PROVER_CC_LIMIT=10

if "%ESCJ_STDARGS%"=="" set ESCJ_STDARGS=-nowarn Deadlock

rem USERPATH is a variable local to this batch file
if "%CLASSPATH%"=="" set USERPATH=.
if not "%CLASSPATH%"=="" set USERPATH=%CLASSPATH%

"%JAVA%" -Dsimplify="%ESCJ_SIMPLIFY% %ESCJ_SIMPLIFY_ARGS%" -classpath "%ESCJAVA_ROOT%\lib\escjava.zip;%JAVA_STDLIB%" escjava.Main -bootclasspath "%ESCJAVA_ROOT%\lib\specs;%JAVA_STDLIB%" -classpath %USERPATH% %ESCJ_STDARGS% %*

endlocal
