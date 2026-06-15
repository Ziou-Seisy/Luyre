module;
#define Version 0,5,0
#define TheName "Luyre"
#define MSVC_MACRO(...) __VA_ARGS__
#define vToString_(a,b,c) #a "." #b "." #c
#define vToString(...) MSVC_MACRO(vToString_(__VA_ARGS__))
export module TheMsg;

export constexpr const char theMessage[] =
" _                                     \n"
"| |     _   _   _   _   _ __   ___   \n"
"| |    | | | | | | | | | '__| / _ \\ \n"
"| |___ | |_| | | |_| | | |   |  __/ \n"
"|_____| \\__,_|  \\__, | |_|    \\___| \n"
"                |___/\n"
TheName "	: A compiled programming language.\n"
"Version	: " vToString(Version)
" [Build: " __DATE__ " " __TIME__ "]\n"
"----------------------------------------------------\n"
"If the configuration file is named config.luyreby, \n"
"then use the following command in the command line:\n"
"````````````````````````````````````````````````````\n"
"	C:\\Users> luyre.exe config.luyreby\n\n"
"````````````````````````````````````````````````````\n"
;

export constexpr const char theName[] = TheName;
export constexpr const int the_Version[3] = { Version };
export constexpr const char theVersionString[] = vToString(Version);