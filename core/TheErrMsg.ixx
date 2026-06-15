export module TheErrMsg;

export constexpr const char errorTooFewCommand[] = "Unexpected error:"
" Too few command line arguments, even less than 1.";
export constexpr const char *errorTooManyCommand[2] = { "Format error:"
"\tToo many command line arguments.\n"
"\t\tIt should require {2}, "
"in the format '<luyre.exe> <config.luyreby>'.\n"
"\t\tBut the current number is: {", "}." };
export constexpr const char *errorFailedToOpenTheFile[2] = { "File error: failed to open the file."
" Its path is: `","`." };