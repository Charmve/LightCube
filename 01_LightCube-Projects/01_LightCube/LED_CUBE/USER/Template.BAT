SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\Program Files\dotnet\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;C:\Users\14296\AppData\Local\Microsoft\WindowsApps;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\Program Files\Bandizip\;c:\Ora10InstantClient;F:\altera\13.1\modelsim_ase\win32aloem;F:\altera\13.0\modelsim_ase\win32aloem
SET CPU_TYPE=STM32F407VETx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Template
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\stm32f4xx_it.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via "..\OBJ\Template.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" "..\OBJ\Template.axf" --i32combined --output "..\OBJ\Template.hex"
