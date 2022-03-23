# bufferOverflowCTF
Exploit the unguarded buffer to overwrite the stack in such a way to print the flag.

The initial version was created taking an input after a prompt, not using command line arguments. Command line arguments make it much easier to provide direct hex values, where the live prompt requires ASCII character conversion. While this provides limited input strategies, the original CTF was implemented on a host using an ssh tunnel and netcat listener that listened for user input to the prompt. The source was intentionally modified to result in a solution composed of typeable ASCII characters. Note that the user running the executable has a limited shell, deterring attackers from opening up a useful reverse shell as an alternative.

The provided executable allows a live demonstration (ie. it works with a specific key--can you derive it?). To create your own, follow the compilation instructions provided in the source file.
