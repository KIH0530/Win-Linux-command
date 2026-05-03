#include <Lmcons.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void enableAnsiColors() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

string getWindowsVersion() {
    OSVERSIONINFOA osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOA));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
    GetVersionExA(&osvi);
    stringstream ss;
    ss << osvi.dwMajorVersion << "." << osvi.dwMinorVersion << " (Build " << osvi.dwBuildNumber << ")";
    return ss.str();
}

string getArchitecture() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) ? "x64" : "x86";
}

int getNumberOfProcessors() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return si.dwNumberOfProcessors;
}

string getRamInfo() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalPhys = memInfo.ullTotalPhys;
    stringstream ss;
    ss << (totalPhys / (1024 * 1024 * 1024)) << " GB";
    return ss.str();
}

string getDiskSpace() {
    ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;
    if (GetDiskFreeSpaceExA("C:\\", &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes)) {
        stringstream ss;
        ss << (totalNumberOfBytes.QuadPart / (1024 * 1024 * 1024)) << " GB";
        return ss.str();
    }
    return "Unknown";
}

string getUptime() {
    ULONGLONG uptime = GetTickCount64() / 1000; // seconds
    int days = uptime / 86400;
    int hours = (uptime % 86400) / 3600;
    int mins = (uptime % 3600) / 60;
    stringstream ss;
    ss << days << "d " << hours << "h " << mins << "m";
    return ss.str();
}

string getResolution() {
    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);
    stringstream ss;
    ss << width << "x" << height;
    return ss.str();
}

string getLocale() {
    char locale[LOCALE_NAME_MAX_LENGTH];
    if (GetLocaleInfoA(LOCALE_USER_DEFAULT, LOCALE_SNAME, locale, LOCALE_NAME_MAX_LENGTH)) {
        return string(locale);
    }
    return "Unknown";
}

vector<string> getWindowsAsciiArt() {
    return {
        "\033[34m        ,.=:!!t3Z3z.,                 \033[0m",
        "\033[34m       :tt:::tt333EE3                \033[0m",
        "\033[34m       Et:::ztt33EEEL \033[31m@Ee.,      ..,\033[0m",
        "\033[34m      ;tt:::tt333EE7 \033[31m;EEEEEEttttt33#\033[0m",
        "\033[34m     :Et:::zt333EEQ. \033[31m$EEEEEttttt33QL\033[0m",
        "\033[34m     it::::tt333EEF \033[31m@EEEEEEttttt33F \033[0m",
        "\033[34m    ;3=*^```\"*4EEV \033[31m:EEEEEEttttt33@. \033[0m",
        "\033[34m    ,.=::::!t=., `\033[31m @EEEEEEtttz33QF \033[0m",
        "\033[34m   ;::::::::zt33)   \033[31m\"4EEEtttji3P* \033[0m",
        "\033[34m  :t::::::::tt33.\033[33m:Z3z.. \033[31m `` \033[33m ,..g. \033[0m",
        "\033[34m  i::::::::zt33F \033[33m AEEEtttt::::ztF \033[0m",
        "\033[34m ;:::::::::t33V \033[33m ;EEEttttt::::t3 \033[0m",
        "\033[34m E::::::::zt33L \033[33m @EEEtttt::::z3F \033[0m",
        "\033[34m{3=*^```\"*4E3) \033[33m ;EEEtttt:::::tZ`\033[0m",
        "\033[34m             ` \033[33m :EEEEtttt::::z7 \033[0m",
        "\033[34m                 \033[33m\"VEzjt:;;z>*` \033[0m"
    };
}

vector<string> getWindows10Art() {
    return {
        "\033[36m        ,.=:!!t3Z3z.,                 \033[0m",
        "\033[36m       :tt:::tt333EE3                \033[0m",
        "\033[36m       Et:::ztt33EEEL \033[35m@Ee.,      ..,\033[0m",
        "\033[36m      ;tt:::tt333EE7 \033[35m;EEEEEEttttt33#\033[0m",
        "\033[36m     :Et:::zt333EEQ. \033[35m$EEEEEttttt33QL\033[0m",
        "\033[36m     it::::tt333EEF \033[35m@EEEEEEttttt33F \033[0m",
        "\033[36m    ;3=*^```\"*4EEV \033[35m:EEEEEEttttt33@. \033[0m",
        "\033[36m    ,.=::::!t=., `\033[35m @EEEEEEtttz33QF \033[0m",
        "\033[36m   ;::::::::zt33)   \033[35m\"4EEEtttji3P* \033[0m",
        "\033[36m  :t::::::::tt33.\033[33m:Z3z.. \033[35m `` \033[33m ,..g. \033[0m",
        "\033[36m  i::::::::zt33F \033[33m AEEEtttt::::ztF \033[0m",
        "\033[36m ;:::::::::t33V \033[33m ;EEEttttt::::t3 \033[0m",
        "\033[36m E::::::::zt33L \033[33m @EEEtttt::::z3F \033[0m",
        "\033[36m{3=*^```\"*4E3) \033[33m ;EEEtttt:::::tZ`\033[0m",
        "\033[36m             ` \033[33m :EEEEtttt::::z7 \033[0m",
        "\033[36m                 \033[33m\"VEzjt:;;z>*` \033[0m"
    };
}

vector<string> getWindows7Art() {
    return {
        "\033[32m        ,.=:!!t3Z3z.,                 \033[0m",
        "\033[32m       :tt:::tt333EE3                \033[0m",
        "\033[32m       Et:::ztt33EEEL \033[31m@Ee.,      ..,\033[0m",
        "\033[32m      ;tt:::tt333EE7 \033[31m;EEEEEEttttt33#\033[0m",
        "\033[32m     :Et:::zt333EEQ. \033[31m$EEEEEttttt33QL\033[0m",
        "\033[32m     it::::tt333EEF \033[31m@EEEEEEttttt33F \033[0m",
        "\033[32m    ;3=*^```\"*4EEV \033[31m:EEEEEEttttt33@. \033[0m",
        "\033[32m    ,.=::::!t=., `\033[31m @EEEEEEtttz33QF \033[0m",
        "\033[32m   ;::::::::zt33)   \033[31m\"4EEEtttji3P* \033[0m",
        "\033[32m  :t::::::::tt33.\033[33m:Z3z.. \033[31m `` \033[33m ,..g. \033[0m",
        "\033[32m  i::::::::zt33F \033[33m AEEEtttt::::ztF \033[0m",
        "\033[32m ;:::::::::t33V \033[33m ;EEEttttt::::t3 \033[0m",
        "\033[32m E::::::::zt33L \033[33m @EEEtttt::::z3F \033[0m",
        "\033[32m{3=*^```\"*4E3) \033[33m ;EEEtttt:::::tZ`\033[0m",
        "\033[32m             ` \033[33m :EEEEtttt::::z7 \033[0m",
        "\033[32m                 \033[33m\"VEzjt:;;z>*` \033[0m"
    };
}

vector<string> getWindowsXPArt() {
    return {
        "\033[31m        ,.=:!!t3Z3z.,                 \033[0m",
        "\033[31m       :tt:::tt333EE3                \033[0m",
        "\033[31m       Et:::ztt33EEEL \033[33m@Ee.,      ..,\033[0m",
        "\033[31m      ;tt:::tt333EE7 \033[33m;EEEEEEttttt33#\033[0m",
        "\033[31m     :Et:::zt333EEQ. \033[33m$EEEEEttttt33QL\033[0m",
        "\033[31m     it::::tt333EEF \033[33m@EEEEEEttttt33F \033[0m",
        "\033[31m    ;3=*^```\"*4EEV \033[33m:EEEEEEttttt33@. \033[0m",
        "\033[31m    ,.=::::!t=., `\033[33m @EEEEEEtttz33QF \033[0m",
        "\033[31m   ;::::::::zt33)   \033[33m\"4EEEtttji3P* \033[0m",
        "\033[31m  :t::::::::tt33.\033[36m:Z3z.. \033[33m `` \033[36m ,..g. \033[0m",
        "\033[31m  i::::::::zt33F \033[36m AEEEtttt::::ztF \033[0m",
        "\033[31m ;:::::::::t33V \033[36m ;EEEttttt::::t3 \033[0m",
        "\033[31m E::::::::zt33L \033[36m @EEEtttt::::z3F \033[0m",
        "\033[31m{3=*^```\"*4E3) \033[36m ;EEEtttt:::::tZ`\033[0m",
        "\033[31m             ` \033[36m :EEEEtttt::::z7 \033[0m",
        "\033[31m                 \033[36m\"VEzjt:;;z>*` \033[0m"
    };
}

int main() {
    enableAnsiColors();

    // Get OS version
    OSVERSIONINFOA osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOA));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
    GetVersionExA(&osvi);

    // Select art based on version
    vector<string> art;
    if (osvi.dwMajorVersion == 10) {
        art = getWindows10Art();
    } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1) {
        art = getWindows7Art();
    } else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1) {
        art = getWindowsXPArt();
    } else {
        art = getWindowsAsciiArt();
    }

    // Get the computer name
    string computerName(MAX_COMPUTERNAME_LENGTH + 1, '\0');
    DWORD size = computerName.size();
    GetComputerNameA(&computerName[0], &size);

    // Get the user name
    string userName(UNLEN + 1, '\0');
    DWORD userSize = userName.size();
    GetUserNameA(&userName[0], &userSize);

    // Get system info
    string windowsVersion = getWindowsVersion();
    string architecture = getArchitecture();
    int numProcessors = getNumberOfProcessors();
    string ram = getRamInfo();
    string disk = getDiskSpace();
    string uptime = getUptime();
    string resolution = getResolution();
    string locale = getLocale();

    // Get directories
    char systemDir[MAX_PATH];
    GetSystemDirectoryA(systemDir, MAX_PATH);
    char windowsDir[MAX_PATH];
    GetWindowsDirectoryA(windowsDir, MAX_PATH);
    string homeDir = getenv("USERPROFILE");

    // Info lines
    vector<string> info = {
        "\033[32m" + userName + "@" + computerName + "\033[0m",
        "\033[32m-------------------\033[0m",
        "\033[36mOS: \033[0mWindows " + windowsVersion,
        "\033[36mArchitecture: \033[0m" + architecture,
        "\033[36mProcessors: \033[0m" + to_string(numProcessors),
        "\033[36mRAM: \033[0m" + ram,
        "\033[36mDisk (C:): \033[0m" + disk,
        "\033[36mUptime: \033[0m" + uptime,
        "\033[36mResolution: \033[0m" + resolution,
        "\033[36mLocale: \033[0m" + locale,
        "\033[36mSystem Directory: \033[0m" + string(systemDir),
        "\033[36mWindows Directory: \033[0m" + string(windowsDir),
        "\033[36mHome Directory: \033[0m" + homeDir
    };

    // Display
    size_t maxLines = max(art.size(), info.size());
    for (size_t i = 0; i < maxLines; ++i) {
        if (i < art.size()) {
            cout << art[i];
        } else {
            cout << string(art[0].length(), ' ');
        }
        cout << "  ";
        if (i < info.size()) {
            cout << info[i];
        }
        cout << endl;
    }

    return 0;
}