@echo off


sdcc -c -mz80  --peep-file peep-rules.txt source/main.c


sdcc -c -mz80  --peep-file peep-rules.txt source/charset.c


sdcc -o sms.ihx -mz80 --no-std-crt0 --data-loc 0xc000 rel/crt0_sms.rel main.rel SMSlib.lib charset.rel


ihx2sms sms.ihx out/sms.sms

REM pause

del *.sym
del *.ihx
del *.lk
del *.noi
del *.rel
del *.lst
del *.asm
del *.map


C:\Users\Zisquier\Documents\Projets\MasterSystem\2023-tests\tools\emulateurs\Emulicious-with-Java64 out/sms.sms
REM C:\Users\Zisquier\Documents\Projets\MasterSystem\2023-tests\tools\emulateurs\Fusion364\Fusion.exe out/sms.sms

quit
