#include <iostream>
#include <Windows.h>
#include <winreg.h> // lib = advapi32

static const char printStatusMsg(LSTATUS status)
{
	return (ERROR_SUCCESS == status) ? printf("[Done] Reboot loop removed.\n") : printf("[Error] Could not delete registry key.\n");
}

static void deleteRegistryKey(const char* key)
{
	auto result = RegDeleteKey(HKEY_LOCAL_MACHINE, key);
	printStatusMsg(result);
}

int main()
{
	std::cout << "Let's fix the VisualStudio Reboot Loop by deleting the RegistryKeys for 32 and 64Bit..\n";

	// delete 32Bit: HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\VisualStudio\Setup\Reboot
	// delete 64Bit: HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\Setup\Reboot
	
	deleteRegistryKey("SOFTWARE\\Microsoft\\VisualStudio\\Setup\\Reboot");	
	deleteRegistryKey("SOFTWARE\\WOW6432Node\\Microsoft\\VisualStudio\\Setup\\Reboot");
	
}